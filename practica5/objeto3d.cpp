#include "objeto3d.h"

Objeto3D::Objeto3D()
{
}

Objeto3D::~Objeto3D()
{
}

TMatrizAfin &Objeto3D::matrix()
{
    return m_matrix;
}

void Objeto3D::setColor(Objeto3D::Color color)
{
    this->m_color = color;
}

Objeto3D::Color Objeto3D::color() const
{
    return m_color;
}
