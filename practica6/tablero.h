#ifndef TABLERO_H
#define TABLERO_H

#include "malla.h"

class Tablero
    : public Malla
{
public:
    enum TableroCara {
        Ninguna   = 0,
        Superior  = 0x01,
        Inferior  = 0x02,
        Izquierda = 0x04,
        Derecha   = 0x08,
        Frontal   = 0x10,
        Trasera   = 0x20
    };

    Tablero(double largo, int numPartesLargo,
            double ancho, int numPartesAncho,
            double grueso, int numPartesGrueso,
            Color color, int textura = -1, TableroCara caras = Ninguna);
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
