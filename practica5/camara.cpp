#include "camara.h"
#include "escena.h"
#include <math.h>

Camara::Camara(PV3f eye, PV3f look, PV3f up, Vista vista)
    : m_vista(vista)
    , m_angulo(90)
    , m_proporcion(1)
    , m_eye(eye)
    , m_look(look)
    , m_up(up)
{
    m_n = (eye - look).normaliza();
    m_u = (up * m_n).normaliza();
    m_v = m_n * m_u;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(m_eye.getX() ,m_eye.getY() ,m_eye.getZ(),
              m_look.getX(),m_look.getY(),m_look.getZ(),
              m_up.getX()  ,m_up.getY()  ,m_up.getZ());

    setModelViewMatrix();
    actualizaCamara();
}

Camara::~Camara()
{
}

void Camara::recargaCamara()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(m_eye.getX() ,m_eye.getY() ,m_eye.getZ(),
              m_look.getX(),m_look.getY(),m_look.getZ(),
              m_up.getX()  ,m_up.getY()  ,m_up.getZ());

    setModelViewMatrix();
    actualizaCamara();
}

void Camara::actualizaCamara()
{
    GLdouble left = Escena::self()->left();
    GLdouble right = Escena::self()->right();
    GLdouble bottom = Escena::self()->bottom();
    GLdouble top = Escena::self()->top();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (m_vista == Ortogonal) {
        glOrtho(left * 5.0, right * 5.0, bottom * 5.0, top * 5.0, 1, 1000);
    } else if(m_vista == Perspectiva) {
        gluPerspective(m_angulo, m_proporcion, 1, 1000);
    } else {
        glOrtho(left, right, bottom, top, 1, 1000);
        GLdouble matrix[16];
        matrix[0] = 1; matrix[4] = 0; matrix[8] = 0; /* -X/Z */ matrix[12] = 0; 
        matrix[1] = 0; matrix[5] = 1; matrix[9] = 0; /* -Y/Z */ matrix[13] = 0;
        matrix[2] = 0; matrix[6] = 0; matrix[10]= 1;           matrix[14] = 0;
        matrix[3] = 0; matrix[7] = 0; matrix[11]= 0;            matrix[15] = 1;
        
    }
}

void Camara::desplazar(Sentido sentido)
{
    switch (sentido) {
        case Izquierda:
            m_eye.setX(m_eye.getX() - 1);
            break;
        case Derecha:
            m_eye.setX(m_eye.getX() + 1);
            break;
        case Adelante:
            m_eye.setZ(m_eye.getZ() - 1);
            break;
        case Atras:
            m_eye.setZ(m_eye.getZ() + 1);
            break;
        case Arriba:
            m_eye.setY(m_eye.getY() + 1);
            break;
        case Abajo:
            m_eye.setY(m_eye.getY() - 1);
            break;
    }
    setModelViewMatrix();
}

void Camara::setModelViewMatrix()
{
    glMatrixMode(GL_MODELVIEW);
    GLdouble matrix[16];
    matrix[0] = m_u.getX();
    matrix[1] = m_v.getX();
    matrix[2] = m_n.getX();
    matrix[3] = 0;

    matrix[4] = m_u.getY();
    matrix[5] = m_v.getY();
    matrix[6] = m_n.getY();
    matrix[7] = 0;

    matrix[8] = m_u.getZ();
    matrix[9] = m_v.getZ();
    matrix[10]= m_n.getZ();
    matrix[11]= 0;

    const PV3f negEye(-m_eye.getX(), -m_eye.getY(), -m_eye.getZ());
    matrix[12]= m_u.dot(negEye);
    matrix[13]= m_v.dot(negEye);
    matrix[14]= m_n.dot(negEye);
    matrix[15]= 1;

    glLoadMatrixd(matrix);
}

void Camara::roll(GLdouble angulo)
{
    const PV3f u(m_u);
    m_u = m_u * cos(angulo) + m_v * sin(angulo);
    m_v = u * -sin(angulo) + m_v * cos(angulo);
    setModelViewMatrix();
}

void Camara::pitch(GLdouble angulo)
{
    const PV3f n(m_n);
    m_n = m_n * cos(angulo) + m_v * sin(angulo);
    m_v = n * -sin(angulo) + m_v * cos(angulo);
    setModelViewMatrix();
}
void Camara::yaw(GLdouble angulo)
{
    const PV3f n(m_n);
    m_n = m_n * cos(angulo) + m_u * sin(angulo);
    m_u = n * -sin(angulo) + m_u * cos(angulo);
    setModelViewMatrix();
}
