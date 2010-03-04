#ifndef HIPOTROCOIDE_H
#define HIPOTROCOIDE_H

#include <GL/gl.h>

class Hipotrocoide
{
public:
    Hipotrocoide();
    virtual ~Hipotrocoide();

    void dibuja();

private:
    int m_a;
    int m_b;
    int m_c;
};

#endif

