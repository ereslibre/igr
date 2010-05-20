#include "mesa.h"
#include "cilindro.h"
#include "tablero.h"

Mesa::Mesa()
{
  // Soporte de la mesa
  m_cilindro = new Cilindro(2, 2, 2.5, 50, 50, Color(0.1, 0.1, 0.1));
  m_cilindro->matriz().rotar(-90, 1, 0, 0);
  m_listaObjetos << m_cilindro;
  // Tablero de la mesa
  m_tablero = new Tablero(7, 20, 5, 20, 0.5, 20, Color(0.2, 0.2, 1.0), 1, (Tablero::TableroCara) (Tablero::Superior | Tablero::Inferior |
                          Tablero::Izquierda | Tablero::Derecha | Tablero::Frontal | Tablero::Trasera));
  m_tablero->matriz().rotar(90, 0, 1, 0);
  m_tablero->matriz().trasladar(-2.5, 0, -3.5);
  m_tablero->matriz().trasladar(0, 2.5, 0);
  m_listaObjetos << m_tablero;
}

Mesa::~Mesa()
{
  delete m_cilindro;
  delete m_tablero;
}
