#ifndef DUPLEX_H
#define DUPLEX_H

#include "objetocompuesto3d.h"

class Duplex
    : public ObjetoCompuesto3D
{
 public:
    Duplex();
    virtual ~Duplex();

 private:
    Objeto3D *m_muebles;
    Objeto3D *m_lampara;
    Objeto3D *m_estanteria;
    Objeto3D *m_tele;
    Objeto3D *m_cuadro;
    Objeto3D *m_sofa;

    Objeto3D *m_suelo;
    Objeto3D *m_techoH1;

    void trasladaMueble(GLdouble x, GLdouble y, GLdouble z);
    void trasladaLampara(GLdouble x, GLdouble y, GLdouble z);
    void escalaMueble(GLdouble x, GLdouble y, GLdouble z);
    void escalaLampara(GLdouble x, GLdouble y, GLdouble z);
    void rotaMueble(GLdouble angulo, GLdouble x, GLdouble y, GLdouble z);
    void rotaLampara(GLdouble angulo, GLdouble x, GLdouble y, GLdouble z);

};

#endif // DUPLEX_H
