#ifndef ESCENA_H
#define ESCENA_H

#include "camara.h"
#include "objeto3d.h"

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
    virtual void keyPressEvent(QKeyEvent *event);

private:
    GLfloat     m_posicionLuz0[4];

    Camara     *m_camara;
    Objeto3D   *m_duplex;
};

#endif

