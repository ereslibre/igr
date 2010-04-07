#ifndef COCHE_H
#define COCHE_H

#include "pv3f.h"

#include <GL/gl.h>
#include <GL/glu.h>

class Hipotrocoide;

class Coche
{
public:
    Coche(Hipotrocoide *hipotrocoide);
    virtual ~Coche();

    void avanza();
    void retrocede();

    void dibuja(GLdouble scale);

private:
    void dibujaRect(GLdouble x, GLdouble y, GLdouble z,GLdouble scale);
    PV3f derivada1(GLdouble t) const;
    PV3f derivada2(GLdouble t) const;
    void dibujaCubo(int i, int j, int k);
    void dibujaRect2(int divX, int divY, int divZ);

private:
    GLUquadric   *m_dis1;
    GLUquadric   *m_dis2;
    GLUquadric   *m_dis3;
    GLUquadric   *m_dis4;
    GLUquadric   *m_rue1;
    GLUquadric   *m_rue2;
    GLUquadric   *m_rue3;
    GLUquadric   *m_rue4;
    int           m_angulo;
    Hipotrocoide *m_hipotrocoide;
    int           m_numX;
    int           m_numY;
    int           m_numZ;
    int           m_numCubos;
    GLdouble      m_largoX;
    GLdouble      m_anchoZ;
    GLdouble      m_altoY;
};

#endif
