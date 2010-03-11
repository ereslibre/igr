#include "frenet.h"

#include <QtCore/QDebug>
#include <math.h>

QList<PV3f> Frenet::marco(const QList<PV3f> &listaPuntos, GLdouble t, GLdouble b)
{
    const PV3f dpc = derivada1(t, b);
    const PV3f ddpc = derivada2(t);
    const PV3f vt = (dpc * pow(dpc.mod(), -1.0)).normaliza();
    const PV3f vb = ((dpc * ddpc) * pow((dpc * ddpc).mod(), -1.0)).normaliza();
    const PV3f vn = (((dpc * ddpc) * dpc) * pow(((dpc * ddpc) * dpc).mod(), -1.0)).normaliza();
    return multMatriz(listaPuntos, vn, vt, vb, t);
}

PV3f Frenet::derivada1(GLdouble t, GLdouble b)
{
    PV3f res(PV3f::Vector);
    res.setX(-sin(t));
    res.setY(cos(t));
    res.setZ(b);
    return res;
}

PV3f Frenet::derivada2(GLdouble t)
{
    PV3f res(PV3f::Vector);
    res.setX(-cos(t));
    res.setY(-sin(t));
    res.setZ(0);
    return res;
}

QList<PV3f> Frenet::multMatriz(const QList<PV3f> &listaPuntos, const PV3f &n, const PV3f &b, const PV3f &t, GLdouble s)
{
    QList<PV3f> res;
    foreach (const PV3f &p, listaPuntos) {
        //NOTE: Es NECESARIO sumar a la función ORIGINAL de la curva la matriz que hemos obtenido
        //      Ver: http://en.wikipedia.org/wiki/Frenet%E2%80%93Serret_formulas#Ribbons_and_Tubes
        res << PV3f(cos(s), sin(s), s / 2.0) + PV3f(n.dot(p), b.dot(p), t.dot(p), PV3f::Vector);
    }
    return res;
}
