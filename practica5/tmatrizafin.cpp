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

void TMatrizAfin::trasladar(double x, double y, double z)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslated(x, y, z);
    GLdouble matriz[16];
    GLdouble afin[16];
    glGetDoublev(GL_MODELVIEW, matriz);
    glGetDoublev(GL_MODELVIEW, afin);
    glPopMatrix();
    postMultiplicar(afin);
}

void TMatrizAfin::trasladar(const PV3f& vec)
{
}

void TMatrizAfin::rotar(double ang, double x, double y, double z)
{

}

void TMatrizAfin::rotar(double ang, const PV3f& vec)
{

}

void TMatrizAfin::escalar(double x, double y, double z)
{

}

void TMatrizAfin::escalar(const PV3f& vec)
{

}

GLdouble *TMatrizAfin::getMatrizAfin()
{
    return m_matriz;
}

void TMatrizAfin::postMultiplicar(GLdouble mm[16])
{
    GLdouble aux[16];

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
    }
}

PV3f TMatrizAfin::multiplicarVector(const PV3f& v)
{

}
