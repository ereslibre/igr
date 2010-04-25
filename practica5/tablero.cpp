#include "tablero.h"

Tablero::Tablero(double largo, int numPartesLargo,
                 double ancho, int numPartesAncho,
                 double grueso, int numPartesGrueso)
    : Malla()
    , m_largo(largo)
    , m_numPartesLargo(numPartesLargo)
    , m_ancho(ancho)
    , m_numPartesAncho(numPartesAncho)
    , m_grueso(grueso)
    , m_numPartesGrueso(numPartesGrueso)
{
}

Tablero::~Tablero()
{
}
