#include "camara.h"
#include <math.h>

Camara::Camara(PV3f eye, PV3f look, PV3f up, Vista vista)
    : m_left(-400)
    , m_right(400)
    , m_top(400)
    , m_bottom(-400)
    , m_near(10)
    , m_far(100)
    , m_vista(vista)
    , m_angulo(0)
    , m_proporcion(1)
    , m_eye(eye)
    , m_look(look)
    , m_up(up)
{
    m_n = (eye-look).normaliza();
    m_u = (up*m_n).normaliza();
    m_v = m_n*m_u;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(m_eye.getX() ,m_eye.getY() ,m_eye.getZ(),
	      m_look.getX(),m_look.getY(),m_look.getZ(),
	      m_up.getX()  ,m_up.getY()  ,m_up.getZ());

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(m_left,m_right,m_bottom,m_top,m_near,m_far);
    if(m_vista == Frustum)
      glFrustum(m_left,m_right,m_bottom,m_top,m_near,m_far);
    else
      gluPerspective(m_angulo,m_proporcion,m_near,m_far);
}

Camara::~Camara()
{
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

    matrix[12]= m_u.dot(m_eye * -1);
    matrix[13]= m_v.dot(m_eye * -1);
    matrix[14]= m_n.dot(m_eye * -1);
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
