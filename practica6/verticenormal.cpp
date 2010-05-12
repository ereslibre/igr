#include "verticenormal.h"

VerticeNormal::VerticeNormal(const PV3f &vertice, const PV3f &normal)
    : m_vertice(vertice)
    , m_normal(normal)
{
}

VerticeNormal::~VerticeNormal()
{
}

void VerticeNormal::setVertice(const PV3f &vertice)
{
    m_vertice = vertice;
}

void VerticeNormal::setNormal(const PV3f &normal)
{
    m_normal = normal;
}

PV3f VerticeNormal::vertice() const
{
    return m_vertice;
}

PV3f VerticeNormal::normal() const
{
    return m_normal;
}
