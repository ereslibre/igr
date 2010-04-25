#ifndef TELEVISION_H
#define TELEVISION_H

#include "objetocompuesto3d.h"
#include "malla.h"

class Television
    : public ObjetoCompuesto3D
    , public Malla
{
public:
    Television();
    virtual ~Television();
};

#endif // TELEVISION_H
