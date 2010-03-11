#include "hipotrocoide.h"
#include "lapiz.h"
#include "frenet.h"

#include <QtCore/QList>
#include <math.h>
#include <boost/math/common_factor.hpp>

Hipotrocoide::Hipotrocoide()
    : m_a(14)
    , m_b(8)
    , m_c(4)
{
}

Hipotrocoide::~Hipotrocoide()
{
}

void Hipotrocoide::dibuja()
{
    const int numVueltas = (m_b / boost::math::gcd(m_a, m_b)) * 100.0;
    const GLdouble stepSize = 2.0 * M_PI / 100.0;
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

// -    //BEGIN: dibuja cuerpo
// -    currStepSize = 0;
// -    glBegin(GL_QUAD_STRIP);
// -    QList<PV3f> ant;
// -    bool invalido = true;
// -    int caras[] = {0, 1, 3, 5};
// -    glColor4f(0, 1.0f, 0, 0.7f);
// -    for (int i = 0; i < 4000; ++i) {
// -        QList<PV3f> res = Frenet::marco(listaPuntos, currStepSize, 0.3);
// -        if (!invalido) {
// -            for (int i = 0; i < 4; ++i) {
// -                glVertex3d(res[caras[i]].getX(), res[caras[i]].getY(), res[caras[i]].getZ());
// -                glVertex3d(ant[caras[i]].getX(), ant[caras[i]].getY(), ant[caras[i]].getZ());
// -            }
// -            glVertex3d(res[caras[0]].getX(), res[caras[0]].getY(), res[caras[0]].getZ());
// -            glVertex3d(ant[caras[0]].getX(), ant[caras[0]].getY(), ant[caras[0]].getZ());
// -        } else {
// -            invalido = false;
// -        }
// -        ant = res;
// -        currStepSize += 0.01;
// -    }
// -    glEnd();
// -    //END: dibuja cuerpo
    
    currStepSize = 0;
    glBegin(GL_POINTS);
    for (int i = 0; i <= numVueltas; ++i) {
        QList<PV3f> res = Frenet::marco(listaPuntos, currStepSize, m_a, m_b, m_c, currStepSize);
        foreach (const PV3f &p, res) {
            glVertex3d(p.getX(), p.getY(), p.getZ());
        }
        currStepSize += stepSize;
    }
    glEnd();
}
