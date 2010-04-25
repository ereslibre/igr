#include "malla.h"

Malla::Malla()
    : Objeto3D()
{
}

Malla::~Malla()
{
}

void Malla::anadeCara(const Cara &cara)
{
    m_caras << cara;
}

void Malla::anadeVertice(const VerticeNormal &verticeNormal)
{
    m_vertices << verticeNormal;
}

QList<Cara> Malla::listaCaras() const
{
    return m_caras;
}

QList<VerticeNormal> Malla::listaVertices() const
{
    return m_vertices;
}
