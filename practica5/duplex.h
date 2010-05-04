#ifndef DUPLEX_H
#define DUPLEX_H

#include "objetocompuesto3d.h"

class Duplex
    : public ObjetoCompuesto3D
{
 public:
    Duplex();
    virtual ~Duplex();

    void trasladaMueble(GLdouble x, GLdouble y, GLdouble z);
    void trasladaLampara(GLdouble x, GLdouble y, GLdouble z);
    void escalaMueble(GLdouble x, GLdouble y, GLdouble z);
    void escalaLampara(GLdouble x, GLdouble y, GLdouble z);
    void rotaMueble(GLdouble angulo, GLdouble x, GLdouble y, GLdouble z);
    void rotaLampara(GLdouble angulo, GLdouble x, GLdouble y, GLdouble z);
    
    void enciendeApaga();
    void abreCierra();

 private:
    Objeto3D *m_muebles;
    Objeto3D *m_lampara;
    Objeto3D *m_estanteria;
    Objeto3D *m_tele;
    Objeto3D *m_cuadro;
    Objeto3D *m_sofa;
    Objeto3D *m_puerta;

    Objeto3D *m_suelo;

    Objeto3D *m_techoH1;
    Objeto3D *m_techoH2;

    Objeto3D *m_paredF1;
    Objeto3D *m_paredF2;
    Objeto3D *m_paredF3;
    Objeto3D *m_paredF4;

    Objeto3D *m_paredD1;
    Objeto3D *m_paredD2;
    Objeto3D *m_paredD3;

    Objeto3D *m_paredI1;
    Objeto3D *m_paredI2;
    Objeto3D *m_paredI3;
    Objeto3D *m_paredI4;

    void creaEscaleras();
};

#endif // DUPLEX_H
