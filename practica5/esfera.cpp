#include "esfera.h"

Esfera::Esfera(GLdouble radio, 
	       int nMeridianos, 
	       int nParalelos, 
	       Color color)
  : ObjetoCuadrico()
  , m_radio(radio)
  , m_nMeridianos(nMeridianos)
  , m_nParalelos(nParalelos)
{
  setColor(color);
}

Esfera::~Esfera()
{
}

void Esfera::dibuja(Modo modo)
{
  glPushMatrix();
  glMultMatrixd(m_matriz.getMatrizAfin());
  glColor3f(m_color.r, m_color.g, m_color.b);
  
  if (modo == Solido){
    gluQuadricDrawStyle(m_obj, GLU_FILL);
  } else {
    gluQuadricDrawStyle(m_obj, GLU_LINE);
  }

  gluSphere(m_obj, m_radio, m_nMeridianos, m_nParalelos);
  glPopMatrix();
}
