#include "cilindro.h"

Cilindro::Cilindro(GLdouble rBase, 
		   GLdouble rCima, 
		   GLdouble altura, 
		   int nLados, 
		   int nParalelos, 
		   Color color)
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

void Cilindro::dibuja(Modo modo)
{
  glPushMatrix();
  glMultMatrixd(m_matriz.getMatrizAfin());
  glColor3f(m_color.r, m_color.g, m_color.b);
  
  if (modo == Solido){
    gluQuadricDrawStyle(m_obj, GLU_FILL);
  } else {
    gluQuadricDrawStyle(m_obj, GLU_LINE);
  }

  gluCylinder(m_obj, m_rBase, m_rCima, m_altura, m_nLados, m_nParalelos);
  glPopMatrix();
}
