#include "cara.h"

Cara::Cara(const QList<PV3f> &vertices)
    : m_vertices(vertices)
{
    newell();
}

Cara::~Cara()
{
}

void Cara::dibuja(DrawType drawType) const
{
    if (drawType  == Wireframe) {
        glBegin(GL_LINES);
    } else {
        glBegin(GL_QUADS);
    }
    foreach (const PV3f &p, m_vertices) {
        glNormal3d(m_normal.getX(), m_normal.getY(), m_normal.getZ());
        glVertex3d(p.getX(), p.getY(), p.getZ());
    }
    glEnd();
}

QList<PV3f> Cara::vertices() const
{
    return m_vertices;
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
        const GLdouble y = m_vertices[i].getY();
        const GLdouble z = m_vertices[i].getZ();
        const GLdouble sucx = m_vertices[suc(i)].getX();
        const GLdouble sucy = m_vertices[suc(i)].getY();
        const GLdouble sucz = m_vertices[suc(i)].getZ();
        nx += (y - sucy) * (z + sucz);
        ny += (z - sucz) * (x + sucx);
        nz += (x - sucx) * (y + sucy);
    }
    m_normal = PV3f(nx, ny, nz, PV3f::Vector);
}
