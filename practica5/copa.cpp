#include "copa.h"
#include "pv3f.h"

#include <math.h>
#include <boost/math/common_factor.hpp>

Copa::Copa()
{
  QList<PV3f> res;
  int precision = 50;
  GLdouble radio = 1;
  GLdouble altura = 0;
  const GLdouble paso = 2.0 * M_PI / ((GLdouble)precision);
  GLdouble pasoActual = 0;
  //GLdouble currStepSize = 0;
  QList<PV3f> ant;
  bool invalido = true;

  for (int j = 0; j < 11; ++j) {

    for (int i = 0; i < precision; ++i) {
      res << PV3f(radio * cos(pasoActual), altura, radio * sin(pasoActual), PV3f::Punto);
      pasoActual += paso;
    }// i

    pasoActual = 0;

    if (!invalido) {
      int k = 48;
      for (int k = 0; k < res.size()-2; ++k) {
	const int sig = (k + 1) % res.size();
	QList<PV3f> vertices;
	const PV3f p1(ant[k].getX(), ant[k].getY(), ant[k].getZ());
	const PV3f p2(ant[sig].getX(), ant[sig].getY(), ant[sig].getZ());
	const PV3f p3(res[sig].getX(), res[sig].getY(), res[sig].getZ());
	const PV3f p4(res[k].getX(), res[k].getY(), res[k].getZ());
	vertices << p1 << p2 << p3 << p4;
	anadeCara(Cara(vertices));
      }// k
    } else {
      invalido = false;
      }
    ant = res;

    radio = -0.1;
    altura += 0.1;
  }// j

}

Copa::~Copa()
{
}
