#include "hipotrocoide.h"
#include "lapiz.h"
#include "frenet.h"

#include <math.h>
#include <boost/math/common_factor.hpp>

Hipotrocoide::Hipotrocoide()
    : m_wireframe(false)
    , m_a(7)
    , m_b(4)
    , m_c(2)
    , m_np(20)
    , m_nq(100)
    , m_coche(new Coche)  
{
    recalcular();
}

Hipotrocoide::~Hipotrocoide()
{
    delete m_coche;
}

void Hipotrocoide::dibuja(GLdouble t, GLdouble rotateX, GLdouble rotateY, GLdouble rotateZ, bool transparencia)
{
    if (transparencia) {
        glColor4f(0, 0, 1.0f, 0.5f);
    } else {
        glColor4f(0, 0, 1.0f, 1.0f);
    }

    glPushMatrix();

    glRotated(rotateX, 1.0, 0, 0);
    glRotated(rotateY, 0, 1.0, 0);
    glRotated(rotateZ, 0, 0, 1.0);

    Cara::DrawType drawType;
    if (m_wireframe) {
        drawType = Cara::Wireframe;
    } else {
        drawType = Cara::Solid;
    }

    foreach (const Cara &c, m_listaCaras) {
        c.dibuja(drawType);
    }

    //BEGIN: dibuja cursor
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
    QList<PV3f> res = Frenet::marco(m_puntosCursor, m_a, m_b, m_c, t, m_mFrenet);
    foreach (const PV3f &p, res) {
        glVertex3d(p.getX(), p.getY(), p.getZ());
    }
    glVertex3d(res[0].getX(), res[0].getY(), res[0].getZ());
    glEnd();
    //END: dibuja cursor
    
    //BEGIN: dibuja coche
    glPushMatrix();
    glLoadIdentity();
    glMultMatrixd(m_mFrenet);
    m_coche->dibuja(0.25);
    glPopMatrix();
    //END: dibuja coche 

    glPopMatrix();
}

void Hipotrocoide::recalcular()
{
    m_listaCaras.clear();
    m_puntosCursor.clear();

    const int numVueltas = (m_b / boost::math::gcd(m_a, m_b)) * ((GLdouble) m_nq);
    const GLdouble stepSize = 2.0 * M_PI / ((GLdouble) m_nq);
    GLdouble currStepSize = 0;

    QList<PV3f> listaPuntos;
    GLdouble radio = 0.5;
    const GLdouble paso = 2.0 * M_PI / ((GLdouble) m_np);
    GLdouble pasoActual = 0;
    for (int i = 0; i < m_np; ++i) {
        listaPuntos << PV3f(radio * cos(pasoActual), radio * sin(pasoActual), 0, PV3f::Punto);
        pasoActual += paso;
    }

    radio += 0.2;
    pasoActual = 0;
    for (int i = 0; i < m_np; ++i) {
        m_puntosCursor << PV3f(radio * cos(pasoActual), radio * sin(pasoActual), 0, PV3f::Punto);
        pasoActual += paso;
    }

    currStepSize = 0;
    QList<PV3f> ant;
    glColor3f(0, 0, 1.0f);
    bool invalido = true;
    for (int i = 0; i <= numVueltas; ++i) {
      QList<PV3f> res = Frenet::marco(listaPuntos, m_a, m_b, m_c, currStepSize, m_mFrenet);
        if (!invalido) {
            for (int j = 0; j < res.size(); ++j) {
                const int sig = (j + 1) % res.size();
                QList<PV3f> vertices;
                const PV3f p1(ant[j].getX(), ant[j].getY(), ant[j].getZ());
                const PV3f p2(ant[sig].getX(), ant[sig].getY(), ant[sig].getZ());
                const PV3f p3(res[sig].getX(), res[sig].getY(), res[sig].getZ());
                const PV3f p4(res[j].getX(), res[j].getY(), res[j].getZ());
                if (m_wireframe) {
                    vertices << p1 << p4 << p2 << p3 << p1 << p2 << p3 << p4;
                } else {
                    vertices << p1 << p2 << p3 << p4;
                }
                m_listaCaras << Cara(vertices);
            }
        } else {
            invalido = false;
        }
        ant = res;
        currStepSize += stepSize;
    }
}

void Hipotrocoide::setWireframe(bool wireframe)
{
    m_wireframe = wireframe;
    recalcular();
}

bool Hipotrocoide::wireframe() const
{
    return m_wireframe;
}

void Hipotrocoide::setA(int value)
{
    m_a = value;
    recalcular();
}

void Hipotrocoide::setB(int value)
{
    m_b = value;
    recalcular();
}

void Hipotrocoide::setC(int value)
{
    m_c = value;
    recalcular();
}

void Hipotrocoide::setNP(int value)
{
    m_np = value;
    recalcular();
}

void Hipotrocoide::setNQ(int value)
{
    m_nq = value;
    recalcular();
}

