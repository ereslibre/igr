#ifndef CILINDRO_H
#define CILINDRO_H

#include "objetocuadrico.h"

class Cilindro
    : public ObjetoCuadrico
{
 public:
  Cilindro(GLdouble rBase, 
	   GLdouble rCima, 
	   GLdouble altura, 
	   int nLados, 
	   int nParalelos, 
	   Color color);
  virtual ~Cilindro();

  virtual void dibuja(Modo modo);

 private:
  GLdouble m_rBase;
  GLdouble m_rCima;
  GLdouble m_altura;
  int m_nLados;
  int m_nParalelos;
};

#endif // CILINDRO_H
