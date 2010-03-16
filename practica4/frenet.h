#ifndef FRENET_H
#define FRENET_H

#include "pv3f.h"

#include <QtCore/QList>

class Frenet
{
public:
  static QList<PV3f> marco(const QList<PV3f> &listaPuntos, GLdouble a, GLdouble b, GLdouble c, GLdouble t, int mF[16]);

private:
    static PV3f derivada1(GLdouble a, GLdouble b, GLdouble c, GLdouble t);
    static PV3f derivada2(GLdouble a, GLdouble b, GLdouble c, GLdouble t);
    static QList<PV3f> multMatriz(const QList<PV3f> &listaPuntos, const PV3f &vn, const PV3f &vb, const PV3f &vt, GLdouble a, GLdouble b, GLdouble c, GLdouble t);
};

#endif
