#ifndef ESCENA_H
#define ESCENA_H

#include <QtOpenGL/QGLWidget>

#define ESCENA_WIDTH  800.0
#define ESCENA_HEIGHT 500.0

class Escena
    : public QGLWidget
{
public:
    Escena(QWidget *parent = 0);
    ~Escena();

protected:
    virtual void initializeGL();
    virtual void paintGL();
};

#endif

