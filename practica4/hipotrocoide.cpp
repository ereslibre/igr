#include "hipotrocoide.h"
#include "lapiz.h"
#include "frenet.h"

#include <QtCore/QList>
#include <math.h>
#include <boost/math/common_factor.hpp>

Hipotrocoide::Hipotrocoide()
    : m_a(14)
    , m_b(8)
    , m_c(4)
{
}

Hipotrocoide::~Hipotrocoide()
{
}

void Hipotrocoide::dibuja()
{
    const int numVueltas = (m_b / boost::math::gcd(m_a, m_b)) * 100.0;
    const GLdouble stepSize = 2.0 * M_PI / 100.0;
    GLdouble currStepSize = 0;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(0, 0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    int numAristas = 0;
    for (int i = 0; i <= numVueltas; ++i) {
#if 1
        glVertex3f((m_a - m_b) * cos(currStepSize) + m_c * cos(currStepSize * (m_a - m_b) / m_b),
                   0,
                   (m_a - m_b) * sin(currStepSize) - m_c * sin(currStepSize * (m_a - m_b) / m_b));
#endif

	currStepSize += stepSize;
    }
    glEnd();
        QList<PV3f> listaPuntos;
 	Lapiz lapiz;
 	lapiz.setPos(PV3f(0, 0, 0, PV3f::Punto));
 	lapiz.avanzar(0.5, Lapiz::NoDejarRastro);
 	lapiz.girar(M_PI / 2.0);
 	lapiz.avanzar(0.5, Lapiz::NoDejarRastro);
 	for (int i = 0; i < 4; ++i) {
 	  listaPuntos << lapiz.getPos();
 	  lapiz.girar(M_PI / 2.0);
 	  lapiz.avanzar(1, Lapiz::NoDejarRastro);
 	}

	currStepSize = 0;
	glBegin(GL_POINTS);
	for (int i = 0; i <= numVueltas; ++i) {
	  QList<PV3f> res = Frenet::marco(listaPuntos, currStepSize, m_a, m_b, m_c);
	  foreach (const PV3f &p, res) {
	    glVertex3d(p.getX(), p.getY(), p.getZ());
	  }
	  currStepSize += stepSize;
	}
	glEnd();
}
