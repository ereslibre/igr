#include "cilindro.h"

Cilindro::Cilindro(GLdouble rBase, GLdouble rCima, GLdouble altura, int nLados, int nParalelos, Color color)
  : ObjetoCuadrico()
  , m_rBase(rBase)
  , m_rCima(rCima)
  , m_altura(altura)
  , m_nLados(nLados)
  , m_nParalelos(nParalelos)
{
  setColor(color);
}

Cilindro::~Cilindro()
{
}

void Cilindro::dibuja()
{
  glPushMatrix();
  glMultMatrixd(m_matriz.getMatrizAfin());
  glColor3f(m_color.r, m_color.g, m_color.b);
  // Aqui debe de ir un if-then para el wireframe
  gluQuadricDrawStyle(m_obj, GLU_FILL);
  gluCylinder(m_obj, m_rBase, m_rCima, m_altura, m_nLados, m_nParalelos);
  glPopMatrix();
}
