#ifndef SILLA_H
#define SILLA_H

#include "objetocompuesto3d.h"

class Silla
    : public ObjetoCompuesto3D
{
 public:
    Silla();
    virtual ~Silla();

 private:
    Objeto3D *m_pata1;
    Objeto3D *m_pata2;
    Objeto3D *m_pata3;
    Objeto3D *m_pata4;
    Objeto3D *m_asiento;
    Objeto3D *m_respaldo;
};

#endif // SILLA_H
