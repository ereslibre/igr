#include "duplex.h"
#include "muebles.h"
#include "lampara.h"
#include "estanteria.h"
#include "tablero.h"
#include "puerta.h"
#include "television.h"
#include "sofa.h"
#include "cuadro.h"

Duplex::Duplex()
{
    // Definimos los muebles
    m_muebles = new Muebles();
    m_listaObjetos << m_muebles;

    // Definimos la lampara
    m_lampara = new Lampara();
    m_lampara->matriz().trasladar(0, 9, 0);
    m_listaObjetos << m_lampara;

    // Definimos la estanteria
    m_estanteria = new Estanteria();
    m_estanteria->matriz().trasladar(6, 6, -5.5);
    m_estanteria->matriz().rotar(-90, 0, 1, 0);
    m_listaObjetos << m_estanteria;

    // Definimos la puerta
    m_puerta = new Puerta();
    m_puerta->matriz().trasladar(13.8, 0, 0);
    m_listaObjetos << m_puerta;

    // Definimos la television
    m_tele = new Television();
    m_tele->matriz().trasladar(8, 12, -5.5);
    m_tele->matriz().rotar(-90, 0, 1, 0);
    m_tele->matriz().escalar(2, 2, 2);
    m_listaObjetos << m_tele;

    // Definimos el cuadro
    m_cuadro = new Cuadro();
    m_cuadro->matriz().trasladar(0, 14, -5.5);
    m_cuadro->matriz().rotar(-90, 0, 1, 0);
    m_cuadro->matriz().escalar(2, 2, 2);
    m_listaObjetos << m_cuadro;

    // Definimos el sofa
    m_sofa = new Sofa();
    m_sofa->matriz().trasladar(0, 9.5, -5.5);
    m_sofa->matriz().rotar(-90, 0, 1, 0);
    m_listaObjetos << m_sofa;

    // Definimos el suelo
    m_suelo = new Tablero(10, 20, 28, 20, 0.5, 20, Color(1, 1, 1), 3, Tablero::Superior);
    m_suelo->matriz().trasladar(-14, -0.5, -6);
    m_listaObjetos << m_suelo;

    // Definimos el techo de la habitacion 1
    m_techoH1 = new Tablero(9.5, 20, 23, 40, 0.5, 20, Color(1, 1, 1), 4, Tablero::Superior);
    m_techoH1->matriz().trasladar(-9, 9, -5.5);
    m_listaObjetos << m_techoH1;
    m_techoH2 = new Tablero(4, 8, 4.8, 9, 0.5, 20, Color(1, 1, 1), 4, Tablero::Superior);
    m_techoH2->matriz().trasladar(-13.8, 9, 0);
    m_listaObjetos << m_techoH2;

    // Definimos la pared del fondo
    m_paredF1 = new Tablero(0.5, 10, 28, 10, 4, 10, Color(1, 1, 1), 2, Tablero::Frontal);
    m_paredF1->matriz().trasladar(-14, 0, -6);
    m_listaObjetos << m_paredF1;
    m_paredF2 = new Tablero(0.5, 10, 28, 10, 10, 10, Color(1, 1, 1), 2, Tablero::Frontal);
    m_paredF2->matriz().trasladar(-14, 8, -6);
    m_listaObjetos << m_paredF2;
    m_paredF3 = new Tablero(0.5, 10, 11.5, 10, 18, 10, Color(1, 1, 1), 2, Tablero::Frontal);
    m_paredF3->matriz().trasladar(2.5, 0, -6);
    m_listaObjetos << m_paredF3;
    m_paredF4 = new Tablero(0.5, 10, 11.5, 10, 18, 10, Color(1, 1, 1), 2, Tablero::Frontal);
    m_paredF4->matriz().trasladar(-14, 0, -6);
    m_listaObjetos << m_paredF4;

    // Definimos la pared derecha
    m_paredD1 = new Tablero(2, 10, 0.2, 10, 9, 10, Color(1, 1, 1), 2, Tablero::Izquierda);
    m_paredD1->matriz().trasladar(13.8, 0, 2);
    m_listaObjetos << m_paredD1;
    m_paredD2 = new Tablero(6, 10, 0.2, 10, 9, 10, Color(1, 1, 1), 2, Tablero::Izquierda);
    m_paredD2->matriz().trasladar(13.8, 0, -6);
    m_listaObjetos << m_paredD2;
    m_paredD3 = new Tablero(2, 10, 0.2, 10, 3, 10, Color(1, 1, 1), 2, Tablero::Izquierda);
    m_paredD3->matriz().trasladar(13.8, 6, 0);
    m_listaObjetos << m_paredD3;

    // Definimos la pared izquierda
    m_paredI1 = new Tablero(3, 10, 0.2, 10, 18, 10, Color(1, 1, 1), 2, Tablero::Derecha);
    m_paredI1->matriz().trasladar(-14, 0, 1);
    m_listaObjetos << m_paredI1;
    m_paredI2 = new Tablero(3, 10, 0.2, 10, 18, 10, Color(1, 1, 1), 2, Tablero::Derecha);
    m_paredI2->matriz().trasladar(-14, 0, -6);
    m_listaObjetos << m_paredI2;
    m_paredI3 = new Tablero(4, 10, 0.2, 10, 12, 10, Color(1, 1, 1), 2, Tablero::Derecha);
    m_paredI3->matriz().trasladar(-14, 0, -3);
    m_listaObjetos << m_paredI3;
    m_paredI4 = new Tablero(4, 10, 0.2, 10, 2, 10, Color(1, 1, 1), 2, Tablero::Derecha);
    m_paredI4->matriz().trasladar(-14, 16, -3);
    m_listaObjetos << m_paredI4;
    creaEscaleras();
}

Duplex::~Duplex()
{
    Q_FOREACH (Objeto3D* o, m_listaObjetos) {
        delete o;
    }
}

void Duplex::trasladaMueble(GLdouble x, GLdouble y, GLdouble z)
{
    m_muebles->matriz().trasladar(x, y, z);
}

void Duplex::trasladaLampara(GLdouble x, GLdouble y, GLdouble z)
{
    m_lampara->matriz().trasladar(x, y, z);
}

void Duplex::escalaMueble(GLdouble x, GLdouble y, GLdouble z)
{
    m_muebles->matriz().escalar(x, y, z);
}

void Duplex::escalaLampara(GLdouble x, GLdouble y, GLdouble z)
{
    m_lampara->matriz().escalar(x, y, z);
    ((Lampara*) m_lampara)->calculaAngulo(y);
}

void Duplex::rotaMueble(GLdouble angulo, GLdouble x, GLdouble y, GLdouble z)
{
    m_muebles->matriz().rotar(angulo, x, y, z);
}

void Duplex::rotaLampara(GLdouble angulo, GLdouble x, GLdouble y, GLdouble z)
{
    m_lampara->matriz().rotar(angulo, x, y, z);
}

void Duplex::enciendeApaga()
{
    m_tele->interactua();
}

void Duplex::abreCierra()
{
    m_puerta->interactua();
}

void Duplex::creaEscaleras()
{
    GLdouble altura = 0;
    GLdouble largo = 8;
    for (int i = 0; i < 10; ++i) {
        Tablero *escalon = new Tablero(largo, 10, 4.8, 10, altura + 1, 20, Color(1, 1, 1));
        escalon->matriz().trasladar(-13.8, altura, -5.5);
        m_listaObjetos << escalon;
        altura += 0.46;
        largo -= 0.8;
    }
}
