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
    listaPuntos << PV3f(0.5, 0.5, 0);
    listaPuntos << PV3f(-0.5, 0.5, 0);
    listaPuntos << PV3f(-0.5, 0.5, 0);
    listaPuntos << PV3f(-0.5, -0.5, 0);
    listaPuntos << PV3f(-0.5, -0.5, 0);
    listaPuntos << PV3f(0.5, -0.5, 0);
    listaPuntos << PV3f(0.5, -0.5, 0);
    listaPuntos << PV3f(0.5, 0.5, 0);
 
    QList<PV3f> listaPuntosMarcador;
    listaPuntosMarcador << PV3f(0.7, 0.7, 0);
    listaPuntosMarcador << PV3f(-0.7, 0.7, 0);
    listaPuntosMarcador << PV3f(-0.7, 0.7, 0);
    listaPuntosMarcador << PV3f(-0.7, -0.7, 0);
    listaPuntosMarcador << PV3f(-0.7, -0.7, 0);
    listaPuntosMarcador << PV3f(0.7, -0.7, 0);
    listaPuntosMarcador << PV3f(0.7, -0.7, 0);
    listaPuntosMarcador << PV3f(0.7, 0.7, 0);

    //BEGIN: dibuja muelle interno
    GLdouble currStepSize = -20;
    glBegin(GL_POINTS);
    for (int i = 0; i < 4000; ++i) {
        glVertex3d(cos(currStepSize), sin(currStepSize), currStepSize / 2.0);
        currStepSize += 0.01;
    }
    glEnd();
    //END: dibuja muelle interno

    //BEGIN: dibuja cuerpo
    currStepSize = 0;
    glBegin(GL_QUAD_STRIP);
    QList<PV3f> ant;
    bool invalido = true;
    int caras[] = {0, 1, 3, 5};
    glColor4f(0, 1.0f, 0, 0.7f);
    for (int i = 0; i < 4000; ++i) {
        QList<PV3f> res = Frenet::marco(listaPuntos, currStepSize, 0.5);
        if (!invalido) {
            for (int i = 0; i < 4; ++i) {
                glVertex3d(res[caras[i]].getX(), res[caras[i]].getY(), res[caras[i]].getZ());
                glVertex3d(ant[caras[i]].getX(), ant[caras[i]].getY(), ant[caras[i]].getZ());
            }
            glVertex3d(res[caras[0]].getX(), res[caras[0]].getY(), res[caras[0]].getZ());
            glVertex3d(ant[caras[0]].getX(), ant[caras[0]].getY(), ant[caras[0]].getZ());
        } else {
            invalido = false;
        }
        ant = res;
        currStepSize += 0.01;
    }
    glEnd();
    //END: dibuja cuerpo

    //BEGIN: dibuja marcador (se mueve con las flechas <- y ->, y es de radio mayor para verlo mejor)
    currStepSize = t;
    glBegin(GL_LINES);
    QList<PV3f> res = Frenet::marco(listaPuntosMarcador, currStepSize, 0.5);
    glColor3f(1.0f, 1.0f, 1.0f);
    foreach (const PV3f &p, res) {
        glVertex3d(p.getX(), p.getY(), p.getZ());
    }
    glEnd();
    //END: dibuja marcador (se mueve con las flechas <- y ->, y es de radio mayor para verlo mejor)
}
