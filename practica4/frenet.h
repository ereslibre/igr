#ifndef FRENET_H
#define FRENET_H

#include "pv3f.h"

#include <QtCore/QList>

class Frenet
{
public:
    static QList<PV3f> marco(const QList<PV3f> &listaPuntos, GLdouble t, int a, int b, int c);

private:
    static PV3f derivada1(GLdouble t, int a, int b, int c);
    static PV3f derivada2(GLdouble t, int a, int b, int c);
    static QList<PV3f> multMatriz(const QList<PV3f> &listaPuntos, const PV3f &n, const PV3f &b, const PV3f &t, const PV3f &c);
};

#endif
