#ifndef ESCENA_H
#define ESCENA_H

#include "hipotrocoide.h"

#include <QtOpenGL/QGLWidget>

class Escena
    : public QGLWidget
{
public:
    Escena(QWidget *parent = 0);
    ~Escena();

protected:
    virtual QSize sizeHint() const;
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int width, int height);

private:
    GLfloat  m_eyeX;
    GLfloat  m_eyeY;
    GLfloat  m_eyeZ;
    GLfloat  m_lookX;
    GLfloat  m_lookY;
    GLfloat  m_lookZ;
    GLfloat  m_upX;
    GLfloat  m_upY;
    GLfloat  m_upZ;
    GLdouble m_near;
    GLdouble m_far;
    GLfloat  m_posicionLuz0[4];

    Hipotrocoide *m_hipotrocoide;
};

#endif

