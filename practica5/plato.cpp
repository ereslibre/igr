#include "plato.h"
#include "disco.h"

Plato::Plato()
{
  // Disco que forma el plato
  m_plato = new Disco(0, 0.4, 20, 10, Color(1, 1, 1));
  m_plato->matriz().rotar(-90, 1, 0, 0);
}

Plato::~Plato()
{
  delete m_plato;
}

void Plato::dibuja(Modo modo)
{
  m_plato->dibuja(modo);
}
