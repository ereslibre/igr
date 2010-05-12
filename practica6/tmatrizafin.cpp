#include "tmatrizafin.h"

TMatrizAfin::TMatrizAfin()
{
    int j = 0;
    for (int i = 0; i < 16; ++i) {
        m_matriz[i] = 0;
    }
    m_matriz[0] = 1;
    m_matriz[5] = 1;
    m_matriz[10] = 1;
    m_matriz[15] = 1;
}

TMatrizAfin::TMatrizAfin(const TMatrizAfin& matriz)
{

}

TMatrizAfin::~TMatrizAfin()
{
}

void TMatrizAfin::cargarIdentidad()
{
    int j = 0;
    for (int i = 0; i < 16; ++i) {
        m_matriz[i] = 0;
    }
    m_matriz[0] = 1;
    m_matriz[5] = 1;
    m_matriz[10] = 1;
    m_matriz[15] = 1;
}

void TMatrizAfin::trasladar(GLdouble x, GLdouble y, GLdouble z)
{
    GLdouble afin[16];
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslated(x, y, z);
    glGetDoublev(GL_MODELVIEW_MATRIX, afin);
    glPopMatrix();
    postMultiplicar(afin);
}

void TMatrizAfin::trasladar(const PV3f& vec)
{
    trasladar(vec.getX(), vec.getY(), vec.getZ());
}

void TMatrizAfin::rotar(GLdouble ang, GLdouble x, GLdouble y, GLdouble z)
{
    GLdouble afin[16];
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glRotated(ang, x, y, z);
    glGetDoublev(GL_MODELVIEW_MATRIX, afin);
    glPopMatrix();
    postMultiplicar(afin);
}

void TMatrizAfin::rotar(GLdouble ang, const PV3f& vec)
{
    rotar(ang, vec.getX(), vec.getY(), vec.getZ());
}

void TMatrizAfin::escalar(GLdouble x, GLdouble y, GLdouble z)
{
    GLdouble afin[16];
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glScaled(x, y, z);
    glGetDoublev(GL_MODELVIEW_MATRIX, afin);
    glPopMatrix();
    postMultiplicar(afin);
}

void TMatrizAfin::escalar(const PV3f& vec)
{
    escalar(vec.getX(), vec.getY(), vec.getZ());
}

GLdouble *TMatrizAfin::getMatrizAfin()
{
    return m_matriz;
}

void TMatrizAfin::postMultiplicar(GLdouble mm[16])
{
  /*GLdouble aux[16];

    aux[0] = m_matriz[0] * mm[0] + m_matriz[4] * mm[1] + m_matriz[8] * mm[2] + m_matriz[12] * mm[3];
    aux[4] = m_matriz[0] * mm[4] + m_matriz[4] * mm[5] + m_matriz[8] * mm[6] + m_matriz[12] * mm[7];
    aux[8] = m_matriz[0] * mm[8] + m_matriz[4] * mm[9] + m_matriz[8] * mm[10] + m_matriz[12] * mm[11];
    aux[12] = m_matriz[0] * mm[12] + m_matriz[4] * mm[13] + m_matriz[8] * mm[14] + m_matriz[12] * mm[15];

    aux[1] = m_matriz[1] * mm[0] + m_matriz[5] * mm[1] + m_matriz[9] * mm[2] + m_matriz[13] * mm[3];
    aux[5] = m_matriz[1] * mm[4] + m_matriz[5] * mm[5] + m_matriz[9] * mm[6] + m_matriz[13] * mm[7];
    aux[9] = m_matriz[1] * mm[8] + m_matriz[5] * mm[9] + m_matriz[9] * mm[10] + m_matriz[13] * mm[11];
    aux[13] = m_matriz[1] * mm[12] + m_matriz[5] * mm[13] + m_matriz[9] * mm[14] + m_matriz[13] * mm[15];

    aux[2] = m_matriz[2] * mm[0] + m_matriz[6] * mm[1] + m_matriz[10] * mm[2] + m_matriz[14] * mm[3];
    aux[6] = m_matriz[2] * mm[4] + m_matriz[6] * mm[5] + m_matriz[10] * mm[6] + m_matriz[14] * mm[7];
    aux[10] = m_matriz[2] * mm[8] + m_matriz[6] * mm[9] + m_matriz[10] * mm[10] + m_matriz[14] * mm[11];
    aux[14] = m_matriz[2] * mm[12] + m_matriz[6] * mm[13] + m_matriz[10] * mm[14] + m_matriz[14] * mm[15];

    aux[3] = m_matriz[3] * mm[0] + m_matriz[7] * mm[1] + m_matriz[11] * mm[2] + m_matriz[15] * mm[3];
    aux[7] = m_matriz[3] * mm[4] + m_matriz[7] * mm[5] + m_matriz[11] * mm[6] + m_matriz[15] * mm[7];
    aux[11] = m_matriz[3] * mm[8] + m_matriz[7] * mm[9] + m_matriz[11] * mm[10] + m_matriz[15] * mm[11];
    aux[15] = m_matriz[3] * mm[12] + m_matriz[7] * mm[13] + m_matriz[11] * mm[14] + m_matriz[15] * mm[15];

    for (int i = 0; i < 16; ++i) {
        m_matriz[i] = aux[i];
	}*/
  glPushMatrix();
  glLoadMatrixd(m_matriz);
  glMultMatrixd(mm);
  glGetDoublev(GL_MODELVIEW_MATRIX, m_matriz);
  glPopMatrix();
}

PV3f TMatrizAfin::multiplicarVector(const PV3f& v)
{

}
