#ifndef CAMARA_H
#define CAMARA_H

#include "pv3f.h"

#include <GL/gl.h>
#include <GL/glu.h>

class Camara
{
 public:
   enum Vista {
       Frustum = 0,
       Perspectiva
   };

   Camara(PV3f eye, PV3f look, PV3f up, Vista vista);
   virtual ~Camara();

   void setModelViewMatrix();
   void roll(GLdouble angulo);
   void pitch(GLdouble angulo);
   void yaw(GLdouble angulo);

 private:
   GLdouble m_left;
   GLdouble m_right;
   GLdouble m_top;
   GLdouble m_bottom;
   GLdouble m_near;
   GLdouble m_far;

   Vista    m_vista;

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
