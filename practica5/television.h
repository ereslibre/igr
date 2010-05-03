#ifndef TELEVISION_H
#define TELEVISION_H

#include "objetocompuesto3d.h"
#include "malla.h"

class Television
    : public ObjetoCompuesto3D
{
 public:
    Television();
    virtual ~Television();

    virtual void interactua();

 private:
    Objeto3D *m_borde;
    Objeto3D *m_pantalla;
    bool m_encendida;
};

#endif // TELEVISION_H
