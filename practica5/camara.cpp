#include "camara.h"
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
}

Camara::~Camara()
{
}

void Camara::actualizaCamara(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)
{
    m_left = left;
    m_right = right;
    m_bottom = bottom;
    m_top = top;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (m_vista == Ortogonal) {
        glOrtho(left, right, bottom, top, 1, 1000);
    } else {
        gluPerspective(m_angulo, m_proporcion, 1, 1000);
    }
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
    m_u = m_u * cos(angulo) + m_v * sin(angulo);
    m_v = m_u * -sin(angulo) + m_v * cos(angulo);
    setModelViewMatrix();
}

void Camara::pitch(GLdouble angulo)
{
    m_n = m_n * cos(angulo) + m_v * sin(angulo);
    m_v = m_n * -sin(angulo) + m_v * cos(angulo);
    setModelViewMatrix();
}
void Camara::yaw(GLdouble angulo)
{
    m_n = m_n * cos(angulo) + m_u * sin(angulo);
    m_u = m_n * -sin(angulo) + m_u * cos(angulo);
    setModelViewMatrix();
}
