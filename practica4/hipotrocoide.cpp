#include "hipotrocoide.h"
#include "lapiz.h"
#include "cara.h"
#include "frenet.h"

#include <QtCore/QDebug>
#include <QtCore/QList>
#include <math.h>
#include <boost/math/common_factor.hpp>

Hipotrocoide::Hipotrocoide()
    : m_a(7)
    , m_b(4)
    , m_c(2)
    , m_np(20)
    , m_nq(100)
{
}

Hipotrocoide::~Hipotrocoide()
{
}

void Hipotrocoide::dibuja(GLdouble t, bool wireframe)
{
    const int numVueltas = (m_b / boost::math::gcd(m_a, m_b)) * ((GLdouble) m_nq);
    const GLdouble stepSize = 2.0 * M_PI / ((GLdouble) m_nq);
    GLdouble currStepSize = 0;
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_LINE_STRIP);
    int numAristas = 0;
    for (int i = 0; i <= numVueltas; ++i) {
        glVertex3f((m_a - m_b) * cos(currStepSize) + m_c * cos(currStepSize * (m_a - m_b) / m_b), 0,
                   (m_a - m_b) * sin(currStepSize) - m_c * sin(currStepSize * (m_a - m_b) / m_b));
        currStepSize += stepSize;
    }
    glEnd();

    QList<PV3f> listaPuntos;
    GLdouble radio = 0.5;
    const GLdouble paso = 2.0 * M_PI / ((GLdouble) m_np);
    GLdouble pasoActual = 0;
    for (int i = 0; i < m_np; ++i) {
        listaPuntos << PV3f(radio * cos(pasoActual), radio * sin(pasoActual), 0, PV3f::Punto);
        pasoActual += paso;
    }

    QList<PV3f> listaPuntosCursor;
    radio += 0.2;
    pasoActual = 0;
    for (int i = 0; i < m_np; ++i) {
        listaPuntosCursor << PV3f(radio * cos(pasoActual), radio * sin(pasoActual), 0, PV3f::Punto);
        pasoActual += paso;
    }

    currStepSize = 0;
    QList<PV3f> ant;
    glColor3f(0, 0, 1.0f);
    bool invalido = true;
    QList<Cara> listaCaras;
    for (int i = 0; i <= numVueltas; ++i) {
        QList<PV3f> res = Frenet::marco(listaPuntos, m_a, m_b, m_c, currStepSize);
        if (!invalido) {
            for (int j = 0; j < res.size(); ++j) {
                const int sig = (j + 1) % res.size();
                QList<PV3f> vertices;
                const PV3f p1(ant[j].getX(), ant[j].getY(), ant[j].getZ());
                const PV3f p2(ant[sig].getX(), ant[sig].getY(), ant[sig].getZ());
                const PV3f p3(res[sig].getX(), res[sig].getY(), res[sig].getZ());
                const PV3f p4(res[j].getX(), res[j].getY(), res[j].getZ());
                vertices << p1 << p2 << p3 << p4;
                listaCaras << Cara(vertices);
            }
        } else {
            invalido = false;
        }
        ant = res;
        currStepSize += stepSize;
    }

    Cara::DrawType drawType;
    if (wireframe) {
        drawType = Cara::Wireframe;
    } else {
        drawType = Cara::Solid;
    }
    foreach(const Cara &c, listaCaras) {
        c.dibuja(drawType);
    }

    //BEGIN: dibuja cursor
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
    QList<PV3f> res = Frenet::marco(listaPuntosCursor, m_a, m_b, m_c, t);
    foreach (const PV3f &p, res) {
        glVertex3d(p.getX(), p.getY(), p.getZ());
    }
    glVertex3d(res[0].getX(), res[0].getY(), res[0].getZ());
    glEnd();
    //END: dibuja cursor
}

void Hipotrocoide::setA(int value)
{
    m_a = value;
}

void Hipotrocoide::setB(int value)
{
    m_b = value;
}

void Hipotrocoide::setC(int value)
{
    m_c = value;
}

void Hipotrocoide::setNP(int value)
{
    m_np = value;
}

void Hipotrocoide::setNQ(int value)
{
    m_nq = value;
}
