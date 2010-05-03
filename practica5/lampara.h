#ifndef LAMPARA_H
#define LAMPARA_H

#include "objetocuadrico.h"

class Lampara
    : public ObjetoCuadrico
{
 public:
    Lampara();
    virtual ~Lampara();

    virtual void dibuja(Modo modo);

 private:
    Objeto3D *m_tulipa;
    Objeto3D *m_soporte;
};

#endif // LAMPARA_H
