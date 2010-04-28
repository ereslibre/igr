#ifndef ESFERA_H
#define ESFERA_H

#include "objetocuadrico.h"

class Esfera
    : public ObjetoCuadrico
{
 public:
  Esfera(GLdouble radio, int nMeridianos, int nParalelos, Color color);
  virtual ~Esfera();
  
  virtual void dibuja();

 private:
  GLdouble m_radio;
  int m_nMeridianos;
  int m_nParalelos;
};

#endif // ESFERA_H
