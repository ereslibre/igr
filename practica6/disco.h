#ifndef DISCO_H
#define DISCO_H

#include "objetocuadrico.h"

class Disco
    : public ObjetoCuadrico
{
public:
  Disco(GLdouble rInterno, 
	GLdouble rExterno, 
	int nLados, 
	int nAnillos, 
	Color color);
  virtual ~Disco();

  virtual void dibuja(Modo modo);

private:
    GLdouble m_rInterno;
    GLdouble m_rExterno;
    int m_nLados;
    int m_nAnillos;
};

#endif // DISCO_H
