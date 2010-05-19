#ifndef LAMPARA_H
#define LAMPARA_H

#include "objetocuadrico.h"

class Lampara
    : public ObjetoCuadrico
{
 public:
    Lampara();
    virtual ~Lampara();

    void calculaAngulo(GLdouble escaladoY);

    virtual void dibuja(Modo modo);

 private:
    Objeto3D *m_tulipa;
    Objeto3D *m_soporte;
    GLdouble  m_escaladoY;
    GLdouble  m_act;
};

#endif // LAMPARA_H
