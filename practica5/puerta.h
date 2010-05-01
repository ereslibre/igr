#ifndef PUERTA_H
#define PUERTA_H

#include "objetocompuesto3d.h"

class Puerta
    : public ObjetoCompuesto3D
{
 public:
    Puerta();
    virtual ~Puerta();

    virtual void interactua();

 private:
    Objeto3D *m_puerta;
    Objeto3D *m_picaporte1;
    Objeto3D *m_picaporte2;
    bool      m_abierta;
};

#endif // PUERTA_H
