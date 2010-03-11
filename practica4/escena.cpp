#include "escena.h"

#include <math.h>

Escena::Escena(QWidget *parent)
    : QGLWidget(parent)
    , m_t(0)
    , m_hipotrocoide(new Hipotrocoide)
{
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
}

Escena::~Escena()
{
    makeCurrent();
}

QSize Escena::sizeHint() const
{
    return QSize(800, 500);
}

void Escena::initializeGL()
{
    glClearColor(0.6, 0.7, 0.8, 1.0);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
   
    glEnable(GL_LIGHT0);
    const GLfloat luzDifusa[] = {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    const GLfloat luzAmbiente[] = {0.3, 0.3, 0.3, 1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);

    m_posicionLuz0[0] = 25.0;
    m_posicionLuz0[1] = 25.0;
    m_posicionLuz0[2] = 0.0;
    m_posicionLuz0[3] = 1.0;
    glLightfv(GL_LIGHT0, GL_POSITION, m_posicionLuz0);

    glEnable(GL_COLOR_MATERIAL);
    glMaterialf(GL_FRONT, GL_SHININESS, 0.1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);

    m_eyeX = m_eyeY = m_eyeZ = 100.0;
    m_lookX = m_lookY = m_lookZ = 0.0;
    m_upX = m_upZ = 0;
    m_upY = 1;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(m_eyeX, m_eyeY, m_eyeZ, m_lookX, m_lookY, m_lookZ, m_upX, m_upY, m_upZ);

    m_near = 1;
    m_far = 1000;
}

void Escena::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLightfv(GL_LIGHT0,GL_POSITION,m_posicionLuz0);

    glBegin(GL_LINES);
    glColor4f(1.0,0.0,0.0,1.0);
    glVertex3d(0,0,0);
    glVertex3d(10,0,0);

    glColor4f(0.0,1.0,0.0,1.0);
    glVertex3d(0,0,0);
    glVertex3d(0,10,0);

    glColor4f(0.0,0.0,1.0,1.0);
    glVertex3d(0,0,0);
    glVertex3d(0,0,10);
    glEnd();

    m_hipotrocoide->dibuja(m_t);
}

void Escena::resizeGL(int width, int height)
{
    GLfloat ratio = (GLfloat) width / (GLfloat) height;

    GLdouble left;
    GLdouble right;
    GLdouble bottom;
    GLdouble top;
    if (ratio < 1.0) {
        left = -2.0;
        right = 2.0;
        bottom = -2.0 * (1.0 / ratio);
        top = 2.0 * (1.0 / ratio);
    } else {
        left = -2.0 * ratio;
        right = 2.0 * ratio;
        bottom = -2.0;
        top = 2.0;
    }
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(left * 3.0, right * 3.0, bottom * 3.0, top * 3.0, m_near, m_far);
}

void Escena::keyPressEvent(QKeyEvent *event)
{
    m_t += 100.0;
    update();
    QGLWidget::keyPressEvent(event);
}
