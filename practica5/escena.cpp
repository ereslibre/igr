#include "escena.h"
#include "camara.h"
#include "duplex.h"

#include <math.h>
#include <QtGui/QMainWindow>
#include <QtGui/QKeyEvent>
#include <QtGui/QMenuBar>

Escena *Escena::s_self = 0;

Escena::Escena(QWidget *parent)
    : QGLWidget(parent)
    , m_camara(0)
    , m_camara2(0)
    , m_esCamaraLibre(true)
    , m_manipularNinguno(new QAction("Ninguno", this))
    , m_manipularCamara(new QAction("Camara", this))
    , m_manipularMuebles(new QAction("Muebles", this))
    , m_manipularLampara(new QAction("Lampara", this))
    , m_camaraLibre(new QAction("Libre", this))
    , m_camaraEsquina1(new QAction("Esquina", this))
    , m_camaraFrontal1(new QAction("Frontal", this))
    , m_camaraLateral1(new QAction("Lateral", this))
    , m_camaraCenital1(new QAction("Cenital", this))
    , m_camaraEsquina2(new QAction("Esquina", this))
    , m_camaraFrontal2(new QAction("Frontal", this))
    , m_camaraLateral2(new QAction("Lateral", this))
    , m_camaraCenital2(new QAction("Cenital", this))
{
    s_self = this;

    connect(m_camaraLibre, SIGNAL(triggered()), this, SLOT(camaraLibre()));
    connect(m_camaraEsquina1, SIGNAL(triggered()), this, SLOT(camaraEsquina1()));
    connect(m_camaraFrontal1, SIGNAL(triggered()), this, SLOT(camaraFrontal1()));
    connect(m_camaraLateral1, SIGNAL(triggered()), this, SLOT(camaraLateral1()));
    connect(m_camaraCenital1, SIGNAL(triggered()), this, SLOT(camaraCenital1()));
    connect(m_camaraEsquina2, SIGNAL(triggered()), this, SLOT(camaraEsquina2()));
    connect(m_camaraFrontal2, SIGNAL(triggered()), this, SLOT(camaraFrontal2()));
    connect(m_camaraLateral2, SIGNAL(triggered()), this, SLOT(camaraLateral2()));
    connect(m_camaraCenital2, SIGNAL(triggered()), this, SLOT(camaraCenital2()));

    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);

    QMenuBar *menuBar = new QMenuBar(parent);

    m_manipularNinguno->setCheckable(true);
    m_manipularNinguno->setChecked(true);
    m_manipularCamara->setCheckable(true);
    m_manipularMuebles->setCheckable(true);
    m_manipularLampara->setCheckable(true);
    
    QActionGroup *actionGroup = new QActionGroup(this);
    actionGroup->addAction(m_manipularNinguno);
    actionGroup->addAction(m_manipularCamara);
    actionGroup->addAction(m_manipularMuebles);
    actionGroup->addAction(m_manipularLampara);

    QMenu *controlEscena = new QMenu("Control Escena", this);
    controlEscena->addActions(actionGroup->actions());
    menuBar->addMenu(controlEscena);

    QMenu *habitacion1 = new QMenu("Habitacion 1", this);
    habitacion1->addAction(m_camaraEsquina1);
    habitacion1->addAction(m_camaraFrontal1);
    habitacion1->addAction(m_camaraLateral1);
    habitacion1->addAction(m_camaraCenital1);

    QMenu *habitacion2 = new QMenu("Habitacion 2", this);
    habitacion2->addAction(m_camaraEsquina2);
    habitacion2->addAction(m_camaraFrontal2);
    habitacion2->addAction(m_camaraLateral2);
    habitacion2->addAction(m_camaraCenital2);

    QMenu *posicionCamara = new QMenu("Camara", this);
    posicionCamara->addAction(m_camaraLibre);
    posicionCamara->addMenu(habitacion1);
    posicionCamara->addMenu(habitacion2);
    menuBar->addMenu(posicionCamara);

    static_cast<QMainWindow*>(parent)->setMenuBar(menuBar);
}

Escena::~Escena()
{
    makeCurrent();

    delete m_camara;
    delete m_camara2;
    delete m_duplex;
}

Escena *Escena::self()
{
    if (!s_self) {
        s_self = new Escena;
    }
    return s_self;
}

GLdouble Escena::left() const
{
    return m_left;
}

GLdouble Escena::right() const
{
    return m_right;
}

GLdouble Escena::bottom() const
{
    return m_bottom;
}

GLdouble Escena::top() const
{
    return m_top;
}

QSize Escena::sizeHint() const
{
    return QSize(800, 600);
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

    m_camara = new Camara(PV3f(10.0, 10.0, 10.0), PV3f(0, 0, 0), PV3f(0, 1, 0, PV3f::Vector), Camara::Perspectiva);
    m_duplex = new Duplex();
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
    m_duplex->dibuja(Objeto3D::Solido);
    glPopMatrix();
}

void Escena::resizeGL(int width, int height)
{
    GLfloat ratio = (GLfloat) width / (GLfloat) height;

    if (ratio < 1.0) {
        m_left = -2.0;
        m_right = 2.0;
        m_bottom = -2.0 * (1.0 / ratio);
        m_top = 2.0 * (1.0 / ratio);
    } else {
        m_left = -2.0 * ratio;
        m_right = 2.0 * ratio;
        m_bottom = -2.0;
        m_top = 2.0;
    }
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, width, height);

    m_camara->actualizaCamara();
}

void Escena::keyPressEvent(QKeyEvent *event)
{
    bool doUpdate = true;
    switch (event->key()) {
        case Qt::Key_Space:
            m_duplex->abreCierra();
            break;
        case Qt::Key_Return:
            m_duplex->enciendeApaga();
            break;
        default:
            break;
    }
    if (m_esCamaraLibre) {
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
            case Qt::Key_Space:
                break;
            case Qt::Key_Return:
                break;
            default:
                QGLWidget::keyPressEvent(event);
                doUpdate = false;
                break;
        }
    }
    if (doUpdate) {
        update();
    }
}

void Escena::camaraLibre()
{
    if (m_camara2) {
        m_esCamaraLibre = true;
        delete m_camara;
        m_camara = m_camara2;
        m_camara2 = 0;
        m_camara->recargaCamara();
    }
}

void Escena::camaraEsquina1()
{
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_camara = new Camara(PV3f(14.0, 8.0, 5.0), PV3f(-14.0, 0, -5), PV3f(0, 1, 0, PV3f::Vector), Camara::Ortogonal);
}

void Escena::camaraFrontal1()
{
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_camara = new Camara(PV3f(0, 5.0, 18.0), PV3f(0, 5, 0), PV3f(0, 1, 0, PV3f::Vector), Camara::Ortogonal);
}

void Escena::camaraLateral1()
{
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_camara = new Camara(PV3f(16, 5.0, 0), PV3f(0, 5, 0), PV3f(0, 1, 0, PV3f::Vector), Camara::Ortogonal);
}

void Escena::camaraCenital1()
{
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_camara = new Camara(PV3f(0, 5.0, 0), PV3f(0, 0, 0), PV3f(1, 0, 0, PV3f::Vector), Camara::Ortogonal);
}

void Escena::camaraEsquina2()
{
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_camara = new Camara(PV3f(14.0, 22.0, 5.0), PV3f(-14.0, 12, -5), PV3f(0, 1, 0, PV3f::Vector), Camara::Ortogonal);
}

void Escena::camaraFrontal2()
{
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_camara = new Camara(PV3f(0, 16.0, 18.0), PV3f(0, 16, 0), PV3f(0, 1, 0, PV3f::Vector), Camara::Ortogonal);
}

void Escena::camaraLateral2()
{
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_camara = new Camara(PV3f(16, 16.0, 0), PV3f(0, 16, 0), PV3f(0, 1, 0, PV3f::Vector), Camara::Ortogonal);
}

void Escena::camaraCenital2()
{
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_camara = new Camara(PV3f(0, 16.0, 0), PV3f(0, 0, 0), PV3f(1, 0, 0, PV3f::Vector), Camara::Ortogonal);
}

#include "escena.moc"
