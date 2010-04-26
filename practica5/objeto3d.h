#ifndef OBJETO3D_H
#define OBJETO3D_H

#include <GL/gl.h>

#include "tmatrizafin.h"

class Objeto3D
{
public:
    struct Color {
        Color()
            : r(0)
            , g(0)
            , b(0)
        {
        }

        GLdouble r;
        GLdouble g;
        GLdouble b;
    };

    Objeto3D();
    virtual ~Objeto3D();

    virtual void dibuja() = 0;

    TMatrizAfin &matriz();

    void setColor(Color color);
    Color color() const;

private:
    TMatrizAfin m_matriz;
    Color       m_color;
    
};

#endif // OBJETO3D_H
