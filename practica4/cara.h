#ifndef CARA_H
#define CARA_H

#include <QtCore/QList>

#include "verticenormal.h"

class Cara
{
public:
    Cara();
    virtual ~Cara();

    void anadeVertice(const VerticeNormal &verticeNormal);

    QList<VerticeNormal> listaVertices() const;

private:
    QList<VerticeNormal> m_vertices;
};

#endif
