#include "objetocuadrico.h"

ObjetoCuadrico::ObjetoCuadrico()
{
  m_obj = gluNewQuadric();
}

ObjetoCuadrico::~ObjetoCuadrico()
{
  gluDeleteQuadric(m_obj);
}
