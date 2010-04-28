#include "disco.h"

Disco::Disco(GLdouble rInterno, GLdouble rExterno, int nLados, int nAnillos)
  : ObjetoCuadrico()
  , m_rInterno(rInterno)
  , m_rExterno(rExterno)
  , m_nLados(nLados)
  , m_nAnillos(nAnillos)
{
}

Disco::~Disco()
{
}

void Disco::dibuja()
{
  glPushMatrix();
  glMultMatrixd(m_matriz.getMatrizAfin());
  glColor3f(m_color.r, m_color.g, m_color.b);
  gluDisk(m_obj, m_rInterno, m_rExterno, m_nLados, m_nAnillos);
  glPopMatrix();
}
