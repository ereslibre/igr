#include "lampara.h"
#include "cilindro.h"
#include "disco.h"

Lampara::Lampara()
{
  // Cilindro que forma la tulipa de la lampara
  m_tulipa = new Cilindro(1, 2, 1, 50, 50, Color(0.2, 1, 0.2));
  m_tulipa->matriz().rotar(90, 1, 0, 0);
  // Disco que forma el soporte de la lampara
  m_soporte = new Disco(0, 1, 50, 10, Color(0.2, 1, 0.2));
  m_soporte->matriz().rotar(-90, 1, 0, 0);
}

Lampara::~Lampara()
{
  delete m_tulipa;
  delete m_soporte;
}

void Lampara::dibuja(Modo modo)
{
  glPushMatrix();
  glMultMatrixd(m_matriz.getMatrizAfin());
  m_tulipa->dibuja(modo);
  m_soporte->dibuja(modo);
  GLfloat luz[] = { 0, 0, 0, 1 };
  GLfloat luz2[] = { 1, 1, 1, 1 };
  GLfloat luzPos[] = { 0, 0, 0, 1 };
  GLfloat luzDir[] = { 0, -1, 0, 0 };
  glLightfv(GL_LIGHT1, GL_AMBIENT, luz);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, luz2);
  glLightfv(GL_LIGHT1, GL_SPECULAR, luz2);
  glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 40);
  glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 3);
  glLightfv(GL_LIGHT1, GL_POSITION, luzPos);
  glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, luzDir);
  glPopMatrix();
}
