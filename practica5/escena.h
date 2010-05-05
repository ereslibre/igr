#ifndef ESCENA_H
#define ESCENA_H

#include <QtOpenGL/QGLWidget>

class QAction;

class Camara;
class Duplex;

class Escena
    : public QGLWidget
{
    Q_OBJECT

public:
    Escena(QWidget *parent = 0);
    ~Escena();

    static Escena *self();

    GLdouble left() const;
    GLdouble right() const;
    GLdouble bottom() const;
    GLdouble top() const;

protected:
    virtual QSize sizeHint() const;
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int width, int height);
    virtual void keyPressEvent(QKeyEvent *event);

private Q_SLOTS:
    void camaraLibre();
    void camaraEsquina1();
    void camaraFrontal1();
    void camaraLateral1();
    void camaraCenital1();
    void camaraEsquina2();
    void camaraFrontal2();
    void camaraLateral2();
    void camaraCenital2();

private:
    static Escena *s_self;

    GLfloat   m_posicionLuz0[4];
    Camara   *m_camara;
    Camara   *m_camara2;
    Duplex   *m_duplex;
    GLdouble  m_left;
    GLdouble  m_right;
    GLdouble  m_bottom;
    GLdouble  m_top;
    bool      m_esCamaraLibre;

    QAction  *m_manipularNinguno;
    QAction  *m_manipularCamara;
    QAction  *m_manipularMuebles;
    QAction  *m_manipularLampara;

    QAction  *m_camaraLibre;

    QAction  *m_camaraEsquina1;
    QAction  *m_camaraFrontal1;
    QAction  *m_camaraLateral1;
    QAction  *m_camaraCenital1;

    QAction  *m_camaraEsquina2;
    QAction  *m_camaraFrontal2;
    QAction  *m_camaraLateral2;
    QAction  *m_camaraCenital2;
};

#endif

