#ifndef ESCENA_H
#define ESCENA_H

#include "hipotrocoide.h"
#include "camara.h"

#include <QtOpenGL/QGLWidget>

class Tablero;
class Disco;
class Esfera;
class Cilindro;

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

    Tablero    *m_tablero;
    Camara     *m_camara;
    Disco      *m_disco;
    Esfera     *m_esfera;
    Cilindro   *m_cilindro;
};

#endif

