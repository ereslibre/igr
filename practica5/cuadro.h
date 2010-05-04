#ifndef CUADRO_H
#define CUADRO_H

#include "objetocompuesto3d.h"

class Cuadro
    : public ObjetoCompuesto3D
{
 public:
  Cuadro();
  virtual ~Cuadro();

 private:
  Objeto3D *m_marco;
  Objeto3D *m_lienzo;
};

#endif // CUADRO_H
