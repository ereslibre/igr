#include "muebles.h"
#include "silla.h"
#include "mesa.h"
#include "plato.h"
#include "copa.h"
#include "hipotrocoide.h"
#include "sofa.h"

Muebles::Muebles()
{
  // Definimos las sillas
  m_sillaIzq = new Silla();
  m_sillaIzq->matriz().trasladar(-5, 0, 0);
  m_sillaIzq->matriz().escalar(1.1, 1.1, 1.1);
  m_listaObjetos << m_sillaIzq;
  m_sillaDer = new Silla();
  m_sillaDer->matriz().trasladar(5, 0, 0);
  m_sillaDer->matriz().escalar(1.1, 1.1, 1.1);
  m_sillaDer->matriz().rotar(180, 0, 1, 0);
  m_listaObjetos << m_sillaDer;
  // Definimos las mesas
  m_mesa = new Mesa();
  m_listaObjetos << m_mesa;
  // Definimos los platos
  m_platoIzq = new Plato();
  m_platoIzq->matriz().trasladar(-2.5, 3.01, 0);
  m_platoIzq->matriz().escalar(2, 2, 2);
  m_listaObjetos << m_platoIzq;
  m_platoDer = new Plato();
  m_platoDer->matriz().trasladar(2.5, 3.01, 0);
  m_platoDer->matriz().escalar(2, 2, 2);
  m_listaObjetos << m_platoDer;
  // Definimos las copas
  m_copaIzq = new Copa();
  m_copaIzq->matriz().trasladar(-2, 3, -1.2);
  m_copaIzq->matriz().escalar(0.3, 0.3, 0.3);
  m_listaObjetos << m_copaIzq;
  m_copaDer = new Copa();
  m_copaDer->matriz().trasladar(2, 3, -1.2);
  m_copaDer->matriz().escalar(0.3, 0.3, 0.3);
  m_listaObjetos << m_copaDer;
  // Definimos las hipotrocoides
  m_hipoIzq = new Hipotrocoide();
  m_hipoIzq->matriz().trasladar(-2.5, 3.02, 0);
  m_hipoIzq->matriz().escalar(0.07, 0.07, 0.07);
  m_listaObjetos << m_hipoIzq;
  m_hipoDer = new Hipotrocoide();
  m_hipoDer->matriz().trasladar(2.5, 3.02, 0);
  m_hipoDer->matriz().escalar(0.07, 0.07, 0.07);
  m_listaObjetos << m_hipoDer;
  // Definimos el sofa
  m_sofa = new Sofa();
  m_sofa->matriz().escalar(1.1, 1.1, 1.1);
  m_sofa->matriz().trasladar(6, 0, -5);
  m_sofa->matriz().rotar(-90, 0, 1, 0);
  m_listaObjetos << m_sofa;
}

Muebles::~Muebles()
{
    delete m_sillaIzq;
    delete m_sillaDer;
    delete m_mesa;
    delete m_platoIzq;
    delete m_platoDer;
    delete m_copaIzq;
    delete m_copaDer;
    delete m_hipoIzq;
    delete m_hipoDer;
    delete m_sofa;
}
