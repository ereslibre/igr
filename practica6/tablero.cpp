#include "tablero.h"

Tablero::Tablero(double largo, int numPartesLargo,
                 double ancho, int numPartesAncho,
                 double grueso, int numPartesGrueso,
                 Color color, int textura = -1, TableroCara caras)
    : Malla()
    , m_largo(largo)
    , m_numPartesLargo(numPartesLargo)
    , m_ancho(ancho)
    , m_numPartesAncho(numPartesAncho)
    , m_grueso(grueso)
    , m_numPartesGrueso(numPartesGrueso)
{
    const GLdouble tamLargo = largo / (GLdouble) numPartesLargo;
    const GLdouble tamAncho = ancho / (GLdouble) numPartesAncho;
    const GLdouble tamGrueso = grueso / (GLdouble) numPartesGrueso;
    setColor(color);

    // Cara inferior
    for (int i = 0; i < numPartesLargo; ++i) {
        for (int j = 0; j < numPartesAncho; ++j) {
            QList<PV3f> vertices;
            vertices << PV3f(j * tamAncho, 0, i * tamLargo);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho, 0, i * tamLargo), PV3f(0, -1, 0)));
            vertices << PV3f(j * tamAncho + tamAncho, 0, i * tamLargo);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho + tamAncho, 0, i * tamLargo), PV3f(0, -1, 0)));     
            vertices << PV3f(j * tamAncho + tamAncho, 0, i * tamLargo + tamLargo);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho + tamAncho, 0, i * tamLargo + tamLargo), PV3f(0, -1, 0)));
            vertices << PV3f(j * tamAncho, 0, i * tamLargo + tamLargo);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho, 0, i * tamLargo + tamLargo), PV3f(0, -1, 0)));
            anadeCara(Cara(vertices));
        }
    }

    // Cara superior
    for (int i = 0; i < numPartesLargo; ++i) {
        for (int j = 0; j < numPartesAncho; ++j) {
            QList<PV3f> vertices;
            vertices << PV3f(j * tamAncho, grueso, i * tamLargo);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho, grueso, i * tamLargo), PV3f(0, 1, 0)));
            vertices << PV3f(j * tamAncho, grueso, i * tamLargo + tamLargo);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho, grueso, i * tamLargo + tamLargo), PV3f(0, 1, 0)));
            vertices << PV3f(j * tamAncho + tamAncho, grueso, i * tamLargo + tamLargo);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho + tamAncho, grueso, i * tamLargo + tamLargo), PV3f(0, 1, 0)));
            vertices << PV3f(j * tamAncho + tamAncho, grueso, i * tamLargo);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho + tamAncho, grueso, i * tamLargo), PV3f(0, 1, 0)));
            anadeCara(Cara(vertices));
        }
    }

    // Cara izquierda
    for (int i = 0; i < numPartesGrueso; ++i) {
        for (int j = 0; j < numPartesLargo; ++j) {
            QList<PV3f> vertices;
            vertices << PV3f(0, i * tamGrueso, j * tamLargo);
            anadeVertice(VerticeNormal(PV3f(0, i * tamGrueso, j * tamLargo), PV3f(-1, 0, 0)));
            vertices << PV3f(0, i * tamGrueso, j * tamLargo + tamLargo);
            anadeVertice(VerticeNormal(PV3f(0, i * tamGrueso, j * tamLargo + tamLargo), PV3f(-1, 0, 0)));
            vertices << PV3f(0, i * tamGrueso + tamGrueso, j * tamLargo + tamLargo);
            anadeVertice(VerticeNormal(PV3f(0, i * tamGrueso + tamGrueso, j * tamLargo + tamLargo), PV3f(-1, 0, 0)));
            vertices << PV3f(0, i * tamGrueso + tamGrueso, j * tamLargo);
            anadeVertice(VerticeNormal(PV3f(0, i * tamGrueso + tamGrueso, j * tamLargo), PV3f(-1, 0, 0)));
            anadeCara(Cara(vertices));
        }
    }
    
    // Cara derecha
    for (int i = 0; i < numPartesGrueso; ++i) {
        for (int j = 0; j < numPartesLargo; ++j) {
            QList<PV3f> vertices;
            vertices << PV3f(ancho, i * tamGrueso, j * tamLargo);
            anadeVertice(VerticeNormal(PV3f(ancho, i * tamGrueso, j * tamLargo), PV3f(1, 0, 0)));
            vertices << PV3f(ancho, i * tamGrueso, j * tamLargo + tamLargo);
            anadeVertice(VerticeNormal(PV3f(ancho, i * tamGrueso, j * tamLargo + tamLargo), PV3f(1, 0, 0)));
            vertices << PV3f(ancho, i * tamGrueso + tamGrueso, j * tamLargo + tamLargo);
            anadeVertice(VerticeNormal(PV3f(ancho, i * tamGrueso + tamGrueso, j * tamLargo + tamLargo), PV3f(1, 0, 0)));
            vertices << PV3f(ancho, i * tamGrueso + tamGrueso, j * tamLargo);
            anadeVertice(VerticeNormal(PV3f(ancho, i * tamGrueso + tamGrueso, j * tamLargo), PV3f(1, 0, 0)));
            anadeCara(Cara(vertices));
        }
    }
    
    // Cara trasera
    for (int i = 0; i < numPartesGrueso; ++i){
        for (int j = 0; j < numPartesAncho; ++j){
            QList<PV3f> vertices;
            vertices << PV3f(j * tamAncho, i * tamGrueso, 0);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho, i * tamGrueso, 0), PV3f(0, 0, -1)));
            vertices << PV3f(j * tamAncho, i * tamGrueso + tamGrueso, 0);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho, i * tamGrueso + tamGrueso, 0), PV3f(0, 0, -1)));           
            vertices << PV3f(j * tamAncho + tamAncho, i * tamGrueso + tamGrueso, 0);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho + tamAncho, i * tamGrueso + tamGrueso, 0), PV3f(0, 0, -1)));
	    vertices << PV3f(j * tamAncho + tamAncho, i * tamGrueso, 0);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho + tamAncho, i * tamGrueso, 0), PV3f(0, 0, -1)));
            anadeCara(vertices);
        }
    }
    
    // Cara frontal
    for (int i = 0; i < numPartesGrueso; ++i){
        for (int j = 0; j < numPartesAncho; ++j){
            QList<PV3f> vertices;
            vertices << PV3f(j * tamAncho, i * tamGrueso, largo);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho, i * tamGrueso, largo), PV3f(0, 0, 1)));
            vertices << PV3f(j * tamAncho + tamAncho, i * tamGrueso, largo);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho + tamAncho, i * tamGrueso, largo), PV3f(0, 0, 1)));
            vertices << PV3f(j * tamAncho + tamAncho, i * tamGrueso + tamGrueso, largo);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho + tamAncho, i * tamGrueso + tamGrueso, largo), PV3f(0, 0, 1)));
            vertices << PV3f(j * tamAncho, i * tamGrueso + tamGrueso, largo);
            anadeVertice(VerticeNormal(PV3f(j * tamAncho, i * tamGrueso + tamGrueso, largo), PV3f(0, 0, 1)));
            anadeCara(vertices);
        }
    } 
}

Tablero::~Tablero()
{
}
