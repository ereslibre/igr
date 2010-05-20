#include "malla.h"

Malla::Malla()
    : Objeto3D()
{
}

Malla::~Malla()
{
}

void Malla::dibuja(Modo modo)
{
    glPushMatrix();
    glMultMatrixd(matriz().getMatrizAfin());
    foreach (const Cara &c, m_caras) {
      glColor3f(m_color.r, m_color.g, m_color.b);
        if (modo == Solido){
            c.dibuja(Cara::Solid);
        } else {
            c.dibuja(Cara::Wireframe);
        }
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
