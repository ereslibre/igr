#include "escena.h"
#include "objeto3d.h"
#include "puerta.h"

#include <math.h>
#include <QtGui/QKeyEvent>

Escena::Escena(QWidget *parent)
    : QGLWidget(parent)
    , m_camara(0)
{
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
}

Escena::~Escena()
{
    makeCurrent();

    delete m_camara;
    delete m_puerta;
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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //m_tablero = new Tablero(5, 20, 5, 20, 1, 2, Objeto3D::Color(1.0, 1.0, 1.0));
    //m_tablero->matriz().rotar(-90, 1, 0, 0);
    //m_tablero->matriz().trasladar(1, 1, 1);
    //m_tablero->matriz().escalar(1, 20, 1);
    //m_disco = new Disco(0, 3, 100, 50, Objeto3D::Color(0.2, 0.5, 0.7));
    m_camara = new Camara(PV3f(10.0, 10.0, 10.0), PV3f(0, 0, 0), PV3f(0, 1, 0, PV3f::Vector), Camara::Perspectiva);
    // m_esfera = new Esfera(3, 50, 50, Objeto3D::Color(0.2, 0.5, 0.7));
    //m_esfera->matriz().trasladar(0, 0, 3);
    // m_cilindro = new Cilindro(3, 3, 3, 100, 100, Objeto3D::Color(0.1, 0.8, 0.8));
    m_puerta = new Puerta();
}

void Escena::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLightfv(GL_LIGHT0,GL_POSITION,m_posicionLuz0);
    glMatrixMode(GL_MODELVIEW);

    glBegin(GL_LINES);
    glColor4f(1.0, 0.0, 0.0, 1.0);
    glVertex3d(0, 0, 0);
    glVertex3d(10, 0, 0);

    glColor4f(0.0, 1.0, 0.0, 1.0);
    glVertex3d(0, 0, 0);
    glVertex3d(0, 10, 0);

    glColor4f(0.0, 0.0, 1.0, 1.0);
    glVertex3d(0, 0, 0);
    glVertex3d(0, 0, 10);
    glEnd();

    glPushMatrix();
    
    m_puerta->dibuja(Objeto3D::Solido);

    glPopMatrix();
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

    m_camara->actualizaCamara(left, right, bottom, top);
}

void Escena::keyPressEvent(QKeyEvent *event)
{
    bool doUpdate = true;
    switch (event->key()) {
        case Qt::Key_Left:
            m_camara->desplazar(Camara::Izquierda);
            break;
        case Qt::Key_Right:
            m_camara->desplazar(Camara::Derecha);
            break;
        case Qt::Key_Up:
            m_camara->desplazar(Camara::Adelante);
            break;
        case Qt::Key_Down:
            m_camara->desplazar(Camara::Atras);
            break;
        case Qt::Key_Comma:
            m_camara->desplazar(Camara::Arriba);
            break;
        case Qt::Key_Period:
            m_camara->desplazar(Camara::Abajo);
            break;
        case Qt::Key_A:
            m_camara->yaw(M_PI / 20.0);
            break;
        case Qt::Key_D:
            m_camara->yaw(-M_PI / 20.0);
            break;
        case Qt::Key_W:
            m_camara->pitch(-M_PI / 20.0);
            break;
        case Qt::Key_S:
            m_camara->pitch(M_PI / 20.0);
            break;
        case Qt::Key_Q:
            m_camara->roll(M_PI / 20.0);
            break;
        case Qt::Key_E:
            m_camara->roll(-M_PI / 20.0);
            break;
        default:
            QGLWidget::keyPressEvent(event);
            doUpdate = false;
            break;
    }
    if (doUpdate) {
        update();
    }
}
