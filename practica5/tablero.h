#ifndef TABLERO_H
#define TABLERO_H

#include "malla.h"

class Tablero
    : public Malla
{
public:
    Tablero(double largo, int numPartesLargo,
            double ancho, int numPartesAncho,
            double grueso, int numPartesGrueso,
	    Color color);
    virtual ~Tablero();

private:
    double m_largo;
    int    m_numPartesLargo;
    double m_ancho;
    int    m_numPartesAncho;
    double m_grueso;
    int    m_numPartesGrueso;
};

#endif
