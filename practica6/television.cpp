#include "television.h"
#include "tablero.h"

Television::Television()
    : ObjetoCompuesto3D()
{
    m_encendida = false;

    // Tablero que forma el borde de la television
    m_borde = new Tablero(3, 20, 0.2, 20, 2, 20, Color(0.2, 0.2, 0.2));
    m_borde->matriz().trasladar(0, 0, -1.5);
    m_listaObjetos << m_borde;

    // Tablero que forma la pantalla de la television
    m_pantalla = new Tablero(2, 20, 0.2, 20, 1.2, 20, Color(0.5, 0.5, 0.5));
    m_pantalla->matriz().trasladar(0.1, 0.5, -1);
    m_listaObjetos << m_pantalla;
}

Television::~Television()
{
    delete m_borde;
    delete m_pantalla;
}

void Television::interactua()
{
    Color color;
    if (!m_encendida) {
        color = Color(0.3, 0.3, 1);
    } else {
        color = Color(0.5, 0.5, 0.5);
    }
    m_encendida = !m_encendida;
    Objeto3D *pantalla = m_listaObjetos[1];
    m_listaObjetos[1] = new Tablero(2, 20, 0.2, 20, 1.2, 20, color);
    m_listaObjetos[1]->matriz().trasladar(0.1, 0.5, -1);
    m_pantalla = m_listaObjetos[1];
    delete pantalla;
}
