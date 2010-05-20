#include "cuadro.h"
#include "tablero.h"

Cuadro::Cuadro()
{
  // Definimos el marco
  m_marco = new Tablero(1.5, 20, 0.1, 20, 1, 20, Color(0.53, 0, 0.08));
  m_marco->matriz().trasladar(0, 0, -0.75);
  m_listaObjetos << m_marco;
  // Definimos el lienzo
  m_lienzo = new Tablero(1, 1, 0.1, 1, 0.6, 1, Color(1, 1, 1), 7, Tablero::Derecha);
  m_lienzo->matriz().trasladar(0.01, 0.25, -0.5);
  m_listaObjetos << m_lienzo;
}

Cuadro::~Cuadro()
{
  delete m_marco;
  delete m_lienzo;
}

