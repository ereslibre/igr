#include "duplex.h"
#include "muebles.h"
#include "lampara.h"
#include "estanteria.h"
#include "tablero.h"

Duplex::Duplex()
{
  // Definimos los muebles
  m_muebles = new Muebles();
  m_listaObjetos << m_muebles;
  // Definimos la lampara
  m_lampara = new Lampara();
  m_lampara->matriz().trasladar(0, 9, 0);
  m_listaObjetos << m_lampara;
  // Definimos la estanteria
  m_estanteria = new Estanteria();
  m_estanteria->matriz().trasladar(6, 6, -5.5);
  m_estanteria->matriz().rotar(-90, 0, 1, 0);
  m_listaObjetos << m_estanteria;

  // Definimos el suelo
  m_suelo = new Tablero(10, 20, 20, 20, 0.5, 20, Color(0.98, 0.34, 0.15));
  m_suelo->matriz().trasladar(-8, -0.5, -5.5);
  m_listaObjetos << m_suelo;
  // Definimos el techo de la habitacion 1
  m_techoH1 = new Tablero(10, 20, 20, 20, 0.5, 20, Color(0.98, 0.34, 0.15));
  m_techoH1->matriz().trasladar(-8, 9, -5.5);
  m_listaObjetos << m_techoH1;
}

Duplex::~Duplex()
{
  delete m_muebles;
  delete m_lampara;
  delete m_estanteria;
  delete m_suelo;
}

void Duplex::trasladaMueble(GLdouble x, GLdouble y, GLdouble z)
{
  m_muebles->matriz().trasladar(x, y, z);
}
void Duplex::trasladaLampara(GLdouble x, GLdouble y, GLdouble z)
{
  m_lampara->matriz().trasladar(x, y, z);
}
void Duplex::escalaMueble(GLdouble x, GLdouble y, GLdouble z)
{
  m_muebles->matriz().escalar(x, y, z);
}
void Duplex::escalaLampara(GLdouble x, GLdouble y, GLdouble z)
{
  m_lampara->matriz().escalar(x, y, z);
}
void Duplex::rotaMueble(GLdouble angulo, GLdouble x, GLdouble y, GLdouble z)
{
  m_muebles->matriz().rotar(angulo, x, y, z);
}
void Duplex::rotaLampara(GLdouble angulo, GLdouble x, GLdouble y, GLdouble z)
{
  m_lampara->matriz().rotar(angulo, x, y, z);
}
