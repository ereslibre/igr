#ifndef SOFA_H
#define SOFA_H

#include "objetocompuesto3d.h"

class Sofa
    : public ObjetoCompuesto3D
{
 public:
    Sofa();
    virtual ~Sofa();

 private:
    Objeto3D* m_asiento;
    Objeto3D* m_respaldo;
    Objeto3D* m_pata1;
    Objeto3D* m_pata2;
    Objeto3D* m_pata3;
    Objeto3D* m_pata4;
    Objeto3D* m_brazoIzq;
    Objeto3D* m_brazoDer;
    Objeto3D* m_embelleIzq;
    Objeto3D* m_embelleDer;
};

#endif // SOFA_H
