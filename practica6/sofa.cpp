#include "sofa.h"
#include "tablero.h"
#include "cilindro.h"
#include "esfera.h"

Sofa::Sofa()
{
  // Tablero que forma el asiento
  m_asiento = new Tablero(5, 20, 1.5, 20, 0.7, 20, Color(0.99, 0.78, 0.02));
  m_asiento->matriz().trasladar(0, 0, -2.5);
  m_asiento->matriz().trasladar(0, 0.8, 0);
  m_listaObjetos << m_asiento;
  // Tablero que forma el respaldo
  m_respaldo = new Tablero(5, 20, 2, 20, 0.4, 20, Color(0.9, 0.78, 0.02));
  m_respaldo->matriz().trasladar(0.4, 0, -2.5);
  m_respaldo->matriz().rotar(90, 0, 0, 1);
  m_respaldo->matriz().trasladar(0.8, 0, 0);
  m_listaObjetos << m_respaldo;
  // Las cuatro patas de la silla(d-i, a-i, d-d, a-d)
  m_pata1 = new Cilindro(0.2, 0.2, 0.8, 50, 50, Color(0.9, 0.78, 0.02));
  m_pata1->matriz().rotar(-90, 1, 0, 0);
  m_pata1->matriz().trasladar(0.2, -2.3, 0);
  m_listaObjetos << m_pata1;

  m_pata2 = new Cilindro(0.2, 0.2, 0.8, 50, 50, Color(0.9, 0.78, 0.02));
  m_pata2->matriz().rotar(-90, 1, 0, 0);
  m_pata2->matriz().trasladar(0.2, 2.3, 0);
  m_listaObjetos << m_pata2;
  
  m_pata3 = new Cilindro(0.2, 0.2, 0.8, 50, 50, Color(0.9, 0.78, 0.02));
  m_pata3->matriz().rotar(-90, 1, 0, 0);
  m_pata3->matriz().trasladar(0.2, -2.3, 0);
  m_pata3->matriz().trasladar(1.125, 0, 0);
  m_listaObjetos << m_pata3;  

  m_pata4 = new Cilindro(0.2, 0.2, 0.8, 50, 50, Color(0.9, 0.78, 0.02));
  m_pata4->matriz().rotar(-90, 1, 0, 0);
  m_pata4->matriz().trasladar(0.2, 2.3, 0);
  m_pata4->matriz().trasladar(1.125, 0, 0);
  m_listaObjetos << m_pata4;
  // El reposabrazos izquierdo con su embellecedor
  m_brazoIzq = new Cilindro(0.2, 0.2, 1.1, 50, 50, Color(0.9, 0.78, 0.02));
  m_brazoIzq->matriz().rotar(90, 0, 1, 0);
  m_brazoIzq->matriz().trasladar(-2.3, 1.7, 0.4);
  m_listaObjetos << m_brazoIzq;

  m_embelleIzq = new Esfera(0.2, 50, 50, Color(0.9, 0.78, 0.02));
  m_embelleIzq->matriz().rotar(90, 0, 1, 0);
  m_embelleIzq->matriz().trasladar(-2.3, 1.7, 1.5);
  m_listaObjetos << m_embelleIzq;
  // El reposabrazos derecho con su embellecedor
  m_brazoDer = new Cilindro(0.2, 0.2, 1.1, 50, 50, Color(0.9, 0.78, 0.02));
  m_brazoDer->matriz().rotar(90, 0, 1, 0);
  m_brazoDer->matriz().trasladar(2.3, 1.7, 0.4);
  m_listaObjetos << m_brazoDer;

  m_embelleDer = new Esfera(0.2, 50, 50, Color(0.9, 0.78, 0.02));
  m_embelleDer->matriz().rotar(90, 0, 1, 0);
  m_embelleDer->matriz().trasladar(2.3, 1.7, 1.5);
  m_listaObjetos << m_embelleDer;
}

Sofa::~Sofa()
{
  delete m_asiento;
  delete m_respaldo;
  delete m_pata1;
  delete m_pata2;
  delete m_pata3;
  delete m_pata4;
  delete m_brazoIzq;
  delete m_brazoDer;
  delete m_embelleIzq;
  delete m_embelleDer;
}
