#ifndef ESTANTERIA_H
#define ESTANTERIA_H

#include "objetocompuesto3d.h"

class Estanteria
    : public ObjetoCompuesto3D
{
 public:
    Estanteria();
    virtual ~Estanteria();

 private:
    Objeto3D *m_soporte;
    Objeto3D *m_libroH;
    Objeto3D *m_libroH2;
    Objeto3D *m_libroV;
};

#endif // ESTANTERIA_H
