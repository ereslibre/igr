#include <QtGui/QApplication>
#include <QtOpenGL/QGLWidget>

class Test
    : public QGLWidget
{
public:
    Test(QWidget *parent = 0);
    ~Test();

    virtual QSize sizeHint() const;

protected:
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
};

Test::Test(QWidget *parent)
    : QGLWidget(parent)
{
}

Test::~Test()
{
    makeCurrent();
}

QSize Test::sizeHint() const
{
    return QSize(640, 480);
}

void Test::initializeGL()
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

void Test::paintGL()
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
}

void Test::resizeGL(int width, int height)
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
    glOrtho(left, right, bottom, top, m_near, m_far);
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Test test;
    test.show();
    return app.exec();
}
