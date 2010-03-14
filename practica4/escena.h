#ifndef ESCENA_H
#define ESCENA_H

#include "hipotrocoide.h"

#include <QtOpenGL/QGLWidget>

class Escena
    : public QGLWidget
{
    Q_OBJECT

public:
    Escena(QWidget *parent = 0);
    ~Escena();

public Q_SLOTS:
    void aChanged(int value);
    void bChanged(int value);
    void cChanged(int value);
    void npChanged(int value);
    void nqChanged(int value);

protected:
    virtual QSize sizeHint() const;
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int width, int height);
    virtual void keyPressEvent(QKeyEvent *event);

private:
    GLdouble m_t;
    bool     m_wireframe;
    GLdouble m_eyeX;
    GLdouble m_eyeY;
    GLdouble m_eyeZ;
    GLdouble m_lookX;
    GLdouble m_lookY;
    GLdouble m_lookZ;
    GLdouble m_upX;
    GLdouble m_upY;
    GLdouble m_upZ;
    GLdouble m_near;
    GLdouble m_far;
    GLfloat  m_posicionLuz0[4];

    Hipotrocoide *m_hipotrocoide;
};

#endif

