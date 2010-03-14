#ifndef HIPOTROCOIDE_H
#define HIPOTROCOIDE_H

#include "pv3f.h"

#include <GL/gl.h>
#include <GL/glu.h>

class Hipotrocoide
{
public:
    Hipotrocoide();
    virtual ~Hipotrocoide();

    void dibuja(GLdouble t, bool wireframe);

    void setA(int value);
    void setB(int value);
    void setC(int value);
    void setNP(int value);
    void setNQ(int value);

private:
    PV3f derivada1(GLdouble t) const;
    PV3f derivada2(GLdouble t) const;

private:
    int m_a;
    int m_b;
    int m_c;
    int m_np;
    int m_nq;
};

#endif
