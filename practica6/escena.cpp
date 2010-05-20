#include "escena.h"
#include "camara.h"
#include "duplex.h"

#include <math.h>
#include <QtGui/QMainWindow>
#include <QtGui/QKeyEvent>
#include <QtGui/QMenuBar>
#include <QtGui/QImage>
#include <QtOpenGL/QGLWidget>

Escena *Escena::s_self = 0;

Escena::Escena(QWidget *parent)
    : QGLWidget(parent)
    , m_camara(0)
    , m_camara2(0)
    , m_esCamaraLibre(true)
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
    , m_ambiente(new QAction("Ambiente", this))
    , m_lampara(new QAction("Lampara", this))
    , m_remota(new QAction("Remota", this))
    , m_niebla(new QAction("Niebla", this))
    , m_proyeccion(Camara::Perspectiva)
{
    s_self = this;

    QAction *proyeccionOrtogonal = new QAction("Ortogonal", this);
    proyeccionOrtogonal->setCheckable(true);
    QAction *proyeccionPerspectiva = new QAction("Perspectiva", this);
    proyeccionPerspectiva->setCheckable(true);
    proyeccionPerspectiva->setChecked(true);
    QAction *proyeccionOblicua = new QAction("Oblicua", this);
    proyeccionOblicua->setCheckable(true);

    QActionGroup *proyeccionGroup = new QActionGroup(this);
    proyeccionGroup->addAction(proyeccionOrtogonal);
    proyeccionGroup->addAction(proyeccionPerspectiva);
    proyeccionGroup->addAction(proyeccionOblicua);

    m_ambiente->setCheckable(true);
    m_ambiente->setChecked(true);
    m_lampara->setCheckable(true);
    m_remota->setCheckable(true);
    m_niebla->setCheckable(true);

    connect(proyeccionOrtogonal, SIGNAL(triggered()), this, SLOT(proyeccionOrtogonal()));
    connect(proyeccionPerspectiva, SIGNAL(triggered()), this, SLOT(proyeccionPerspectiva()));
    connect(proyeccionOblicua, SIGNAL(triggered()), this, SLOT(proyeccionOblicua()));
    connect(m_camaraLibre, SIGNAL(triggered()), this, SLOT(camaraLibre()));
    connect(m_camaraEsquina1, SIGNAL(triggered()), this, SLOT(camaraEsquina1()));
    connect(m_camaraFrontal1, SIGNAL(triggered()), this, SLOT(camaraFrontal1()));
    connect(m_camaraLateral1, SIGNAL(triggered()), this, SLOT(camaraLateral1()));
    connect(m_camaraCenital1, SIGNAL(triggered()), this, SLOT(camaraCenital1()));
    connect(m_camaraEsquina2, SIGNAL(triggered()), this, SLOT(camaraEsquina2()));
    connect(m_camaraFrontal2, SIGNAL(triggered()), this, SLOT(camaraFrontal2()));
    connect(m_camaraLateral2, SIGNAL(triggered()), this, SLOT(camaraLateral2()));
    connect(m_camaraCenital2, SIGNAL(triggered()), this, SLOT(camaraCenital2()));
    connect(m_ambiente, SIGNAL(triggered()), this, SLOT(recargaLuces()));
    connect(m_lampara, SIGNAL(triggered()), this, SLOT(recargaLuces()));
    connect(m_remota, SIGNAL(triggered()), this, SLOT(recargaLuces()));
    connect(m_niebla, SIGNAL(triggered()), this, SLOT(recargaLuces()));

    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);

    QMenuBar *menuBar = new QMenuBar(parent);

    m_manipularMuebles->setCheckable(true);
    m_manipularMuebles->setChecked(true);
    m_manipularLampara->setCheckable(true);
    
    QActionGroup *actionGroup = new QActionGroup(this);
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

    QMenu *proyeccion = new QMenu("Proyeccion", this);
    proyeccion->addActions(proyeccionGroup->actions());
    menuBar->addMenu(proyeccion);

    QMenu *iluminacion = new QMenu("Iluminacion", this);
    iluminacion->addAction(m_ambiente);
    iluminacion->addAction(m_lampara);
    iluminacion->addAction(m_remota);
    iluminacion->addAction(m_niebla);
    menuBar->addMenu(iluminacion);

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
    glEnable(GL_LIGHTING);
    const GLfloat luzDifusa[] = {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glEnable(GL_LIGHT0);
    
    // Luz lampara
    GLfloat luz[] = { 0, 0, 0, 1 };
    GLfloat luz2[] = { 1, 1, 1, 1 };
    glLightfv(GL_LIGHT1, GL_AMBIENT, luz);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, luz2);
    glLightfv(GL_LIGHT1, GL_SPECULAR, luz2);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 40);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 3);

    // Luz ambiente
    m_posicionLuz0[0] = 25.0;
    m_posicionLuz0[1] = 25.0;
    m_posicionLuz0[2] = 0.0;
    m_posicionLuz0[3] = 1.0;
    glLightfv(GL_LIGHT0, GL_POSITION, m_posicionLuz0);

    // Niebla
    GLfloat colorNiebla[4] = {0.5, 0.5, 0.5, 1.0};
    GLfloat densNiebla = 0.1;
    glFogi(GL_FOG_MODE, GL_EXP2);
    glFogf(GL_FOG_DENSITY, densNiebla);
    glFogfv(GL_FOG_COLOR, colorNiebla);
 
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);
    glMaterialf(GL_FRONT, GL_SHININESS, 0.1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    cargaTexturas();

    m_camara = new Camara(PV3f(10.0, 10.0, 10.0), PV3f(0, 0, 0), PV3f(0, 1, 0, PV3f::Vector), m_proyeccion);
    m_duplex = new Duplex();
}

void Escena::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.5f, 0.6f, 0.7f, 1.0f);

    if (!m_ambiente->isChecked()) {
        GLfloat global_ambient[] = { 0, 0, 0, 1.0f };
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    } else {
        GLfloat global_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    }

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

    m_camara->actualizaCamara(m_proyeccion);
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
        case Qt::Key_I:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->trasladaMueble(0, 0, 1);
            } else {
                m_duplex->trasladaLampara(0, 0, 1);
            }
            break;
        case Qt::Key_K:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->trasladaMueble(0, 0, -1);
            } else {
                m_duplex->trasladaLampara(0, 0, -1);
            }
            break;
        case Qt::Key_J:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->trasladaMueble(-1, 0, 0);
            } else {
                m_duplex->trasladaLampara(-1, 0, 0);
            }
            break;
        case Qt::Key_L:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->trasladaMueble(1, 0, 0);
            } else {
                m_duplex->trasladaLampara(1, 0, 0);
            }
            break;
        case Qt::Key_O:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->trasladaMueble(0, -1, 0);
            } else {
                m_duplex->trasladaLampara(0, -1, 0);
            }
            break;
        case Qt::Key_P:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->trasladaMueble(0, 1, 0);
            } else {
                m_duplex->trasladaLampara(0, 1, 0);
            }
            break;
        case Qt::Key_1:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->escalaMueble(1, 1, 1.5);
            } else {
                m_duplex->escalaLampara(1, 1, 1.5);
            }
            break;
        case Qt::Key_2:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->escalaMueble(1, 1, 0.5);
            } else {
                m_duplex->escalaLampara(1, 1, 0.5);
            }
            break;
        case Qt::Key_3:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->escalaMueble(1.5, 1, 1);
            } else {
                m_duplex->escalaLampara(1.5, 1, 1);
            }
            break;
        case Qt::Key_4:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->escalaMueble(0.5, 1, 1);
            } else {
                m_duplex->escalaLampara(0.5, 1, 1);
            }
            break;
        case Qt::Key_5:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->escalaMueble(1, 1.5, 1);
            } else {
                m_duplex->escalaLampara(1, 1.5, 1);
            }
            break;
        case Qt::Key_6:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->escalaMueble(1, 0.5, 1);
            } else {
                m_duplex->escalaLampara(1, 0.5, 1);
            }
            break;
        case Qt::Key_7:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->rotaMueble(10, 0, 0, 1);
            } else {
                m_duplex->rotaLampara(10, 0, 0, 1);
            }
            break;
        case Qt::Key_8:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->rotaMueble(-10, 0, 0, 1);
            } else {
                m_duplex->rotaLampara(-10, 0, 0, 1);
            }
            break;
        case Qt::Key_9:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->rotaMueble(10, 1, 0, 0);
            } else {
                m_duplex->rotaLampara(10, 1, 0, 0);
            }
            break;
        case Qt::Key_0:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->rotaMueble(-10, 1, 0, 0);
            } else {
                m_duplex->rotaLampara(-10, 1, 0, 0);
            }
            break;
        case Qt::Key_Apostrophe:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->rotaMueble(10, 0, 1, 0);
            } else {
                m_duplex->rotaLampara(10, 0, 1, 0);
            }
            break;
        case Qt::Key_exclamdown:
            if (m_manipularMuebles->isChecked()) {
                m_duplex->rotaMueble(-10, 0, 1, 0);
            } else {
                m_duplex->rotaLampara(-10, 0, 1, 0);
            }
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
            case Qt::Key_Return:
            case Qt::Key_I:
            case Qt::Key_K:
            case Qt::Key_J:
            case Qt::Key_L:
            case Qt::Key_O:
            case Qt::Key_P:
            case Qt::Key_1:
            case Qt::Key_2:
            case Qt::Key_3:
            case Qt::Key_4:
            case Qt::Key_5:
            case Qt::Key_6:
            case Qt::Key_7:
            case Qt::Key_8:
            case Qt::Key_9:
            case Qt::Key_0:
            case Qt::Key_Apostrophe:
            case Qt::Key_exclamdown:
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

void Escena::proyeccionOrtogonal()
{
    m_proyeccion = Camara::Ortogonal;
    Camara *ant = m_camara;
    m_camara = new Camara(ant->getEye(), ant->getLook(), ant->getUp(), m_proyeccion);
    delete ant;
}

void Escena::proyeccionOblicua()
{
    m_proyeccion = Camara::Oblicua;
    Camara *ant = m_camara;
    m_camara = new Camara(ant->getEye(), ant->getLook(), ant->getUp(), m_proyeccion);
    delete ant;
}

void Escena::proyeccionPerspectiva()
{
    m_proyeccion = Camara::Perspectiva;
    Camara *ant = m_camara;
    m_camara = new Camara(ant->getEye(), ant->getLook(), ant->getUp(), m_proyeccion);
    delete ant;
}

void Escena::camaraLibre()
{
    if (m_camara2) {
        m_esCamaraLibre = true;
        delete m_camara;
        m_camara = m_camara2;
        m_camara2 = 0;
        m_camara->recargaCamara(m_proyeccion);
    }
}

void Escena::camaraEsquina1()
{
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_camara = new Camara(PV3f(14.0, 8.0, 5.0), PV3f(-14.0, 0, -5), PV3f(0, 1, 0, PV3f::Vector), m_proyeccion);
}

void Escena::camaraFrontal1()
{
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_camara = new Camara(PV3f(0, 5.0, 18.0), PV3f(0, 5, 0), PV3f(0, 1, 0, PV3f::Vector), m_proyeccion);
}

void Escena::camaraLateral1()
{
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_camara = new Camara(PV3f(22, 5.0, 0), PV3f(0, 5, 0), PV3f(0, 1, 0, PV3f::Vector), m_proyeccion);
}

void Escena::camaraCenital1()
{
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_camara = new Camara(PV3f(0, 9.0, 0), PV3f(0, 0, 0), PV3f(1, 0, 0, PV3f::Vector), m_proyeccion);
}

void Escena::camaraEsquina2()
{
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_camara = new Camara(PV3f(14.0, 22.0, 5.0), PV3f(-14.0, 12, -5), PV3f(0, 1, 0, PV3f::Vector), m_proyeccion);
}

void Escena::camaraFrontal2()
{
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_camara = new Camara(PV3f(0, 16.0, 18.0), PV3f(0, 16, 0), PV3f(0, 1, 0, PV3f::Vector), m_proyeccion);
}

void Escena::camaraLateral2()
{
    m_esCamaraLibre = false;
    if (!m_camara2) {
        m_camara2 = m_camara;
    }
    m_camara = new Camara(PV3f(22, 16.0, 0), PV3f(0, 16, 0), PV3f(0, 1, 0, PV3f::Vector), m_proyeccion);
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
    m_camara = new Camara(PV3f(0, 25, 0), PV3f(0, 0, 0), PV3f(1, 0, 0, PV3f::Vector), m_proyeccion);
}

void Escena::recargaLuces()
{
    if (!m_ambiente->isChecked()) {
        glDisable(GL_LIGHT0);
    } else {
        glEnable(GL_LIGHT0);
    }
    if (m_lampara->isChecked()) {
        glEnable(GL_LIGHT1);
    } else {
        glDisable(GL_LIGHT1);
    }
    if (m_remota->isChecked()) {
        glEnable(GL_LIGHT2);
    } else {
        glDisable(GL_LIGHT2);
    }
    if (m_niebla->isChecked()) {
        glEnable(GL_FOG);
    } else {
        glDisable(GL_FOG);
    }
}

void Escena::cargaTexturas()
{
    QImage t;
    QImage b;

    if (!b.load("/home/ereslibre/facultad/igr/practica6/texturas/parquet.bmp")) {
        return;
    }

    // Convertimos el bmp al formato de openGL
    t = QGLWidget::convertToGLFormat(b);
    GLuint texture[1];
    glGenTextures(1, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, t.width(), t.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, t.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

}

#include "escena.moc"
