#include "puerta.h"
#include "tablero.h"
#include "esfera.h"

Puerta::Puerta()
{
  // Establecemos que la puerta esta cerrada por defecto.
  m_abierta = false;
  // Establecemos la puerta.
  m_puerta = new Tablero(2, 20, 0.2, 20, 6, 20, Color(0.98, 0.34, 0.15));
  m_listaObjetos << m_puerta;
  // Establecemos los picaportes
  m_picaporte1 = new Esfera(0.1, 20, 20, Color(0.9, 0.78, 0.02));
  m_picaporte1->matriz().trasladar(0.25, 3, 1.7);
  m_listaObjetos << m_picaporte1;
  m_picaporte2 = new Esfera(0.1, 20, 20, Color(0.9, 0.78, 0.02));
  m_picaporte2->matriz().trasladar(-0.05, 3, 1.7);
  m_listaObjetos << m_picaporte2;
}

Puerta::~Puerta()
{
  delete m_puerta;
  delete m_picaporte1;
  delete m_picaporte2;
}

void Puerta::interactua()
{
  if(m_abierta == false)
  {
    m_matriz.rotar(90, 0, 1, 0);
    m_abierta = true;
  }else {
    m_matriz.rotar(-90, 0, 1, 0);
    m_abierta = false;
  }
}
