#include "disco.h"

Disco::Disco(GLdouble rInterno, 
	     GLdouble rExterno, 
	     int nLados, 
	     int nAnillos, 
	     Color color)
  : ObjetoCuadrico()
  , m_rInterno(rInterno)
  , m_rExterno(rExterno)
  , m_nLados(nLados)
  , m_nAnillos(nAnillos)
{
  setColor(color);
}

Disco::~Disco()
{
}

void Disco::dibuja(Modo modo)
{
  glPushMatrix();
  glMultMatrixd(m_matriz.getMatrizAfin());
  glColor3f(m_color.r, m_color.g, m_color.b);
  
  if (modo == Solido){
    gluQuadricDrawStyle(m_obj, GLU_FILL);
  } else {
    gluQuadricDrawStyle(m_obj, GLU_LINE);
  }

  gluDisk(m_obj, m_rInterno, m_rExterno, m_nLados, m_nAnillos);
  glPopMatrix();
}
