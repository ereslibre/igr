#include "objeto3d.h"

Objeto3D::Objeto3D()
    : m_matriz(TMatrizAfin())
{
}

Objeto3D::~Objeto3D()
{
}

TMatrizAfin &Objeto3D::matriz()
{
    return m_matriz;
}

void Objeto3D::setColor(Objeto3D::Color color)
{
    this->m_color = color;
}

Objeto3D::Color Objeto3D::color() const
{
    return m_color;
}
