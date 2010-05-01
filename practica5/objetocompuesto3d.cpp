#include "objetocompuesto3d.h"

ObjetoCompuesto3D::ObjetoCompuesto3D()
{
}

ObjetoCompuesto3D::~ObjetoCompuesto3D()
{
}

void ObjetoCompuesto3D::dibuja(Modo modo)
{
  glPushMatrix();
  glMultMatrixd(m_matriz.getMatrizAfin());

  foreach(Objeto3D *obj, m_listaObjetos){
    obj->dibuja(modo);
  }

  glPopMatrix();
}
