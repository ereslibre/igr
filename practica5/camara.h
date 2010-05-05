#ifndef CAMARA_H
#define CAMARA_H

#include "pv3f.h"

#include <GL/gl.h>
#include <GL/glu.h>

class Camara
{
 public:
   enum Vista {
       Ortogonal = 0,
       Perspectiva,
       Oblicua
   };

   enum Sentido {
       Izquierda = 0,
       Derecha,
       Adelante,
       Atras,
       Arriba,
       Abajo
   };

   Camara(PV3f eye, PV3f look, PV3f up, Vista vista);
   virtual ~Camara();

   void recargaCamara(Vista vista);
   void actualizaCamara(Vista vista);
   void desplazar(Sentido sentido);

   void setModelViewMatrix();
   void roll(GLdouble angulo);
   void pitch(GLdouble angulo);
   void yaw(GLdouble angulo);

   PV3f getEye() const;
   PV3f getUp() const;
   PV3f getLook() const;

 private:
   GLdouble m_near;
   GLdouble m_far;

   GLdouble m_angulo;
   GLdouble m_proporcion;

   PV3f m_eye;  //Punto
   PV3f m_look; //Punto
   PV3f m_up;   //Vector

   PV3f m_u;    //Vector
   PV3f m_v;    //Vector
   PV3f m_n;    //Vector
};

#endif
