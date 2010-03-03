#include "cara.h"

Cara::Cara()
{
}

Cara::~Cara()
{
}

void Cara::anadeVertice(const VerticeNormal &verticeNormal)
{
    m_vertices << verticeNormal;
}

QList<VerticeNormal> Cara::listaVertices() const
{
    return m_vertices;
}
