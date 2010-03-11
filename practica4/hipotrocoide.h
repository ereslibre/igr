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

    void dibuja(GLdouble t);
};

#endif
