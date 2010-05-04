#include "copa.h"
#include "pv3f.h"

#include <math.h>
#include <boost/math/common_factor.hpp>

Copa::Copa()
{
  setColor(Color(0.5, 0.5, 0.5));
  dibujaBase();
  dibujaTallo();
  dibujaBaseCuerpo();
  dibujaCuerpo(); 
}

Copa::~Copa()
{
}

QList<PV3f> Copa::dibujaCirculo(GLdouble altura, GLdouble radio)
{
  QList<PV3f> res;
  int precision = 50;

  const GLdouble paso = 2.0 * M_PI / ((GLdouble)precision);
  GLdouble pasoActual = 0;

  for (int i = 0; i < precision; ++i) {
    res << PV3f(radio * cos(pasoActual), altura, radio * sin(pasoActual), PV3f::Punto);
    pasoActual += paso;
  }

  return res;
}

void Copa::dibujaBase()
{
  QList<PV3f> ant;
  bool invalido = true;
  GLdouble altura = 0;
  GLdouble radio = 1;
  for (int i = 0; i <= 5; ++i) {
    QList<PV3f> res = dibujaCirculo(altura, radio);
    if(!invalido) {
      for (int j = 0; j < res.size(); ++j) {
	const int sig = (j + 1) % res.size();
	QList<PV3f> vertices;
	const PV3f p1(ant[j].getX(), ant[j].getY(), ant[j].getZ());
	const PV3f p2(ant[sig].getX(), ant[sig].getY(), ant[sig].getZ());
	const PV3f p3(res[sig].getX(), res[sig].getY(), res[sig].getZ());
	const PV3f p4(res[j].getX(), res[j].getY(), res[j].getZ());
             
	vertices << p1 << p2 << p3 << p4;
	anadeCara(Cara(vertices));
      }
    } else {
      invalido = false;
    }
    ant = res;
    altura += 0.1;
    radio -= 0.15;
  }
}

void Copa::dibujaTallo()
{
  QList<PV3f> ant;
  bool invalido = true;
  GLdouble altura = 0.5;
  GLdouble radio = 0.25;
  for (int i = 0; i <= 10; ++i) {
    QList<PV3f> res = dibujaCirculo(altura, radio);
    if(!invalido) {
      for (int j = 0; j < res.size(); ++j) {
	const int sig = (j + 1) % res.size();
	QList<PV3f> vertices;
	const PV3f p1(ant[j].getX(), ant[j].getY(), ant[j].getZ());
	const PV3f p2(ant[sig].getX(), ant[sig].getY(), ant[sig].getZ());
	const PV3f p3(res[sig].getX(), res[sig].getY(), res[sig].getZ());
	const PV3f p4(res[j].getX(), res[j].getY(), res[j].getZ());
        
	vertices << p1 << p2 << p3 << p4;
	anadeCara(Cara(vertices));
      }
    } else {
      invalido = false;
    }
    ant = res;
    altura += 0.3;
  }
}

void Copa::dibujaBaseCuerpo()
{
  QList<PV3f> ant;
  bool invalido = true;
  GLdouble altura = 3.5;
  GLdouble radio = 0.25;
  for (int i = 0; i <= 5; ++i) {
    QList<PV3f> res = dibujaCirculo(altura, radio);
    if(!invalido) {
      for (int j = 0; j < res.size(); ++j) {
	const int sig = (j + 1) % res.size();
	QList<PV3f> vertices;
	const PV3f p1(ant[j].getX(), ant[j].getY(), ant[j].getZ());
	const PV3f p2(ant[sig].getX(), ant[sig].getY(), ant[sig].getZ());
	const PV3f p3(res[sig].getX(), res[sig].getY(), res[sig].getZ());
	const PV3f p4(res[j].getX(), res[j].getY(), res[j].getZ());
        
	vertices << p1 << p2 << p3 << p4;
	anadeCara(Cara(vertices));
      }
    } else {
      invalido = false;
    }
    ant = res;
    altura += 0.2;
    radio += 0.1;
  }
}

void Copa::dibujaCuerpo()
{
  QList<PV3f> ant;
  bool invalido = true;
  GLdouble altura = 4.5;
  GLdouble radio = 0.75;
  for (int i = 0; i <= 10; ++i) {
    QList<PV3f> res = dibujaCirculo(altura, radio);
    if(!invalido) {
      for (int j = 0; j < res.size(); ++j) {
	const int sig = (j + 1) % res.size();
	QList<PV3f> vertices;
	const PV3f p1(ant[j].getX(), ant[j].getY(), ant[j].getZ());
	const PV3f p2(ant[sig].getX(), ant[sig].getY(), ant[sig].getZ());
	const PV3f p3(res[sig].getX(), res[sig].getY(), res[sig].getZ());
	const PV3f p4(res[j].getX(), res[j].getY(), res[j].getZ());
        
	vertices << p1 << p2 << p3 << p4;
	anadeCara(Cara(vertices));
      }
    } else {
      invalido = false;
    }
    ant = res;
    altura += 0.1;
  }
}
