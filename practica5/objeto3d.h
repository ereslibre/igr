#ifndef OBJETO3D_H
#define OBJETO3D_H

#include <GL/gl.h>

class Objeto3D
{
public:
    struct Color {
        GLdouble r;
        GLdouble g;
        GLdouble b;
    };

    Objeto3D();
    virtual ~Objeto3D();

    void setMatrix(GLdouble **matrix);
    GLdouble **matrix() const;

    void setColor(Color color);
    Color color() const;

private:
    GLdouble m_matrix[16];
    Color    m_color;
    
};

#endif // OBJETO3D_H
