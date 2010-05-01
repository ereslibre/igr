#include "silla.h"
#include "tablero.h"
#include "cilindro.h"

Silla::Silla()
{
  // Tablero que forma el asiento
  m_asiento = new Tablero(1, 20, 1.5, 20, 0.3, 20, Color(0.99, 0.78, 0.02));
  m_asiento->matriz().trasladar(0, 0, -0.5);
  m_asiento->matriz().trasladar(0, 1.2, 0);
  m_listaObjetos << m_asiento;
  // Tablero que forma el respaldo
  m_respaldo = new Tablero(1, 20, 2, 20, 0.4, 20, Color(0.9, 0.78, 0.02));
  m_respaldo->matriz().trasladar(0.4, 0, -0.5);
  m_respaldo->matriz().rotar(90, 0, 0, 1);
  m_respaldo->matriz().trasladar(1.2, 0, 0);
  m_listaObjetos << m_respaldo;
  // Las cuatro patas de la silla(d-i, a-i, d-d, a-d)
  m_pata1 = new Cilindro(0.2, 0.2, 1.2, 50, 50, Color(0.9, 0.78, 0.02));
  m_pata1->matriz().rotar(-90, 1, 0, 0);
  m_pata1->matriz().trasladar(0.2, -0.25, 0);
  m_listaObjetos << m_pata1;

  m_pata2 = new Cilindro(0.2, 0.2, 1.2, 50, 50, Color(0.9, 0.78, 0.02));
  m_pata2->matriz().rotar(-90, 1, 0, 0);
  m_pata2->matriz().trasladar(0.2, 0.25, 0);
  m_listaObjetos << m_pata2;
  
  m_pata3 = new Cilindro(0.2, 0.2, 1.2, 50, 50, Color(0.9, 0.78, 0.02));
  m_pata3->matriz().rotar(-90, 1, 0, 0);
  m_pata3->matriz().trasladar(0.2, -0.25, 0);
  m_pata3->matriz().trasladar(1.125, 0, 0);
  m_listaObjetos << m_pata3;  

  m_pata4 = new Cilindro(0.2, 0.2, 1.2, 50, 50, Color(0.9, 0.78, 0.02));
  m_pata4->matriz().rotar(-90, 1, 0, 0);
  m_pata4->matriz().trasladar(0.2, 0.25, 0);
  m_pata4->matriz().trasladar(1.125, 0, 0);
  m_listaObjetos << m_pata4;
}

Silla::~Silla()
{
  delete m_asiento;
  delete m_respaldo;
  delete m_pata1;
  delete m_pata2;
  delete m_pata3;
  delete m_pata4;
}
