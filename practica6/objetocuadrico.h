#ifndef OBJETOCUADRICO_H
#define OBJETOCUADRICO_H

#include "objeto3d.h"
#include <GL/glu.h>

class ObjetoCuadrico
    : public Objeto3D
{
public:
    ObjetoCuadrico();
    virtual ~ObjetoCuadrico();

protected:
    GLUquadric* m_obj;
};

#endif // OBJETOCUADRICO_H
