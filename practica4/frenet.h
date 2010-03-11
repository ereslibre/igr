#ifndef FRENET_H
#define FRENET_H

#include "pv3f.h"

#include <QtCore/QList>

class Frenet
{
public:
    static QList<PV3f> marco(const QList<PV3f> &listaPuntos, GLdouble t, GLdouble b);

private:
    static PV3f derivada1(GLdouble t, GLdouble b);
    static PV3f derivada2(GLdouble t);
    static QList<PV3f> multMatriz(const QList<PV3f> &listaPuntos, const PV3f &n, const PV3f &b, const PV3f &t, GLdouble s, GLdouble bb);
};

#endif
