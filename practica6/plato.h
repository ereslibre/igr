#ifndef PLATO_H
#define PLATO_H

#include "objetocuadrico.h"

class Plato
    : public ObjetoCuadrico
{
 public:
    Plato();
    virtual ~Plato();

    virtual void dibuja(Modo modo);

 private:
    Objeto3D *m_plato;
};

#endif // PLATO_H
