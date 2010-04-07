#ifndef LAPIZ_H
#define LAPIZ_H

#include <QtCore/QStack>
#include "pv3f.h"

class Lapiz
{
public:
    enum Comportamiento {
        DejarRastro = 0,
        NoDejarRastro
    };

    Lapiz();

    void salvaEstado();
    void recuperaEstado();

    void girar(GLdouble radianes);
    void avanzar(GLdouble distancia, Comportamiento comportamiento = DejarRastro);

    void setDir(GLdouble dir);
    void setPos(const PV3f &pos);

    GLdouble getDir() const;
    const PV3f &getPos() const;

private:
    struct Estado {
        GLdouble dir;
        PV3f     pos;
    } m_e;
    QStack<Estado> m_pilaEstados;
};

#endif
