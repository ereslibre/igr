#include "cara.h"

Cara::Cara(const QList<PV3f> &vertices)
    : m_vertices(vertices)
{
    newell();
}

Cara::~Cara()
{
}

QList<PV3f> Cara::listaVertices() const
{
    return m_vertices;
}

PV3f Cara::normal() const
{
    return m_normal;
}

int Cara::suc(int i) const
{
    return (i + 1) % m_vertices.count();
}

void Cara::newell()
{
    GLdouble nx = 0;
    GLdouble ny = 0;
    GLdouble nz = 0;
    for (int i = 0; i < m_vertices.count(); ++i) {
        const GLdouble x = m_vertices[i].getX();
        const GLdouble y = m_vertices[i].getX();
        const GLdouble z = m_vertices[i].getX();
        const GLdouble sucx = m_vertices[suc(i)].getX();
        const GLdouble sucy = m_vertices[suc(i)].getY();
        const GLdouble sucz = m_vertices[suc(i)].getZ();
        nx += (y - sucy) * (z + sucz);
        ny += (z - sucz) * (x + sucx);
        nz += (x - sucx) * (y + sucy);
    }
    m_normal = PV3f(nx, ny, nz, PV3f::Vector);
}
