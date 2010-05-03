#include "estanteria.h"
#include "tablero.h"

Estanteria::Estanteria()
{
  // Tablero que forma el soporte
  m_soporte = new Tablero(5, 20, 1, 20, 0.4, 20, Color(0.99, 0.7, 0.02));
  m_soporte->matriz().trasladar(0, 0, -2.5);
  m_listaObjetos << m_soporte;
  // Tablero que forma un libro horizontal
  m_libroH = new Tablero(0.3, 20, 0.5, 20, 2, 20, Color(0.2, 1, 0.2));
  m_libroH->matriz().trasladar(0, 0, 1.5);
  m_listaObjetos << m_libroH;
  // Tablero que forma un libro horizontal
  m_libroH2 = new Tablero(0.3, 20, 0.5, 20, 2, 20, Color(0.8, 1, 0.2));
  m_libroH2->matriz().trasladar(0, 0, 1);
  m_listaObjetos << m_libroH2;
  // Tablero que forma un libro vertical
  m_libroV = new Tablero(1.1, 20, 0.5, 20, 0.3, 20, Color(0.2, 1, 1));
  m_libroV->matriz().trasladar(0, 0.4, -1.5);
  m_listaObjetos << m_libroV;
}

Estanteria::~Estanteria()
{
  delete m_soporte;
  delete m_libroH;
  delete m_libroH2;
  delete m_libroV;
}
