#ifndef OBJETOCOMPUESTO3D_H
#define OBJETOCOMPUESTO3D_H

#include "objeto3d.h"

#include <QtCore/QList>

class ObjetoCompuesto3D
    : public Objeto3D
{
public:
    ObjetoCompuesto3D();
    virtual ~ObjetoCompuesto3D();

private:
    QList<Objeto3D*> m_listaObjetos;
};

#endif // OBJETOCOMPUESTO3D_H
