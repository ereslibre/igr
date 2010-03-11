#include "hipotrocoide.h"
#include "lapiz.h"
#include "frenet.h"

#include <QtCore/QDebug>
#include <QtCore/QList>
#include <math.h>
#include <boost/math/common_factor.hpp>

Hipotrocoide::Hipotrocoide()
{
}

Hipotrocoide::~Hipotrocoide()
{
}

void Hipotrocoide::dibuja(GLdouble t)
{
    glColor3f(1.0, 1.0, 1.0);
    
    QList<PV3f> listaPuntos;
    listaPuntos << PV3f(1, 1, 0);
    listaPuntos << PV3f(-1, 1, 0);
    listaPuntos << PV3f(-1, 1, 0);
    listaPuntos << PV3f(-1, -1, 0);
    listaPuntos << PV3f(-1, -1, 0);
    listaPuntos << PV3f(1, -1, 0);
    listaPuntos << PV3f(1, -1, 0);
    listaPuntos << PV3f(1, 1, 0);
 
    GLdouble currStepSize = 0;
    glBegin(GL_POINTS);
    for (int i = 0; i < 1000; ++i) {
        glVertex3d(cos(currStepSize), sin(currStepSize), currStepSize);
        currStepSize += 0.01;
    }
    glEnd();

    currStepSize = 0;
    glBegin(GL_LINES);
    for (int i = 0; i < 100; ++i) {
        QList<PV3f> res = Frenet::marco(listaPuntos, currStepSize, 0.5);
        foreach (const PV3f &p, res) {
            glVertex3d(p.getX(), p.getY(), p.getZ());
        }
        currStepSize += 0.1;
    }
    glEnd();
}
