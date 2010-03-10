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

    void dibuja();

private:
    PV3f derivada1(GLdouble t) const;
    PV3f derivada2(GLdouble t) const;
    

private:
    int m_a;
    int m_b;
    int m_c;
};

#endif
