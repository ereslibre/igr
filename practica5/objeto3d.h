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
      
        Color(GLdouble red, GLdouble green, GLdouble blue)
	    : r(red)
	    , g(green)
	    , b(blue)
        {
	}


        GLdouble r;
        GLdouble g;
        GLdouble b;
    };

    enum Modo {
        Solido = 0,
	Wireframe
    };

    Objeto3D();
    virtual ~Objeto3D();

    virtual void dibuja(Modo modo) = 0;
    virtual void interactua();

    TMatrizAfin &matriz();

    void setColor(Color color);
    Color color() const;

protected:
    TMatrizAfin m_matriz;
    Color       m_color;
    
};

#endif // OBJETO3D_H
