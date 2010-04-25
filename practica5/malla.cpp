#include "malla.h"

Malla::Malla()
    : Objeto3D()
{
}

Malla::~Malla()
{
}

void Malla::dibuja()
{
    glPushMatrix();
    //glMultMatrixd(matrix());
    foreach (const Cara &c, m_caras) {
        glColor3f(1.0, 1.0, 1.0);
        c.dibuja(Cara::Solid);
        glColor3f(0, 0, 1.0);
        c.dibuja(Cara::Wireframe);
    }
    glPopMatrix();
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
