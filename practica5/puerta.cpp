#include "puerta.h"
#include "tablero.h"
#include "esfera.h"

Puerta::Puerta()
{
  // Establecemos que la puerta esta cerrada por defecto.
  m_abierta = false;
  // Establecemos la puerta.
  m_puerta = new Tablero(5, 20, 2, 20, 0.3, 20, Color(0.98, 0.34, 0.15));
  m_listaObjetos << m_puerta;
}

Puerta::~Puerta()
{
  delete m_puerta;
  delete m_picaporte1;
  delete m_picaporte2;
}

void Puerta::interactua()
{
}
