#ifndef COPA_H
#define COPA_H

#include "malla.h"
#include "pv3f.h"

class Copa
    : public Malla
{
 public:
    Copa();
    virtual ~Copa();

 private:
    QList<PV3f> lista;

    QList<PV3f> dibujaCirculo(GLdouble altura, GLdouble radio);
    void dibujaBase();
    void dibujaTallo();
    void dibujaBaseCuerpo();
    void dibujaCuerpo();
};

#endif // COPA_H
