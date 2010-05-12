#ifndef MUEBLES_H
#define MUEBLES_H

#include "objetocompuesto3d.h"

class Muebles
    : public ObjetoCompuesto3D
{
 public:
    Muebles();
    virtual ~Muebles();

 private:
    Objeto3D *m_sillaIzq;
    Objeto3D *m_sillaDer;
    Objeto3D *m_mesa;
    Objeto3D *m_platoIzq;
    Objeto3D *m_platoDer;
    Objeto3D *m_copaIzq;
    Objeto3D *m_copaDer;
    Objeto3D *m_hipoIzq;
    Objeto3D *m_hipoDer;
    Objeto3D *m_sofa;
};

#endif // MUEBLES_H
