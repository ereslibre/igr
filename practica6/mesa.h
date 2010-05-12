#ifndef MESA_H
#define MESA_H

#include "objetocompuesto3d.h"

class Mesa
    : public ObjetoCompuesto3D
{
 public:
    Mesa();
    virtual ~Mesa();
        
 private:
    Objeto3D *m_cilindro;
    Objeto3D *m_tablero;
};

#endif // MESA_H
