#ifndef MALLA_H
#define MALLA_H

#include "objeto3d.h"
#include "cara.h"
#include "verticenormal.h"

class Malla
    : public Objeto3D
{
public:
    Malla();
    virtual ~Malla();

    virtual void dibuja(Modo modo);

    void anadeCara(const Cara &cara);
    void anadeVertice(const VerticeNormal &verticeNormal);

    QList<Cara> listaCaras() const;
    QList<VerticeNormal> listaVertices() const;

private:
    QList<Cara>          m_caras;
    QList<VerticeNormal> m_vertices;
};

#endif
