#include "frenet.h"

#include <QtCore/QDebug>
#include <math.h>

QList<PV3f> Frenet::marco(const QList<PV3f> &listaPuntos, GLdouble t, GLdouble b)
{
    const PV3f dpc = derivada1(t, b);
    const PV3f ddpc = derivada2(t);
    const PV3f vt = dpc * pow(dpc.mod(), -1.0);
    const PV3f vb = (dpc * ddpc) * pow((dpc * ddpc).mod(), -1.0);
    const PV3f vn = ((dpc * ddpc) * dpc) * pow(((dpc * ddpc) * dpc).mod(), -1.0);
    
    return multMatriz(listaPuntos, vn, vb, vt);
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

QList<PV3f> Frenet::multMatriz(const QList<PV3f> &listaPuntos, const PV3f &n, const PV3f &b, const PV3f &t)
{
    QList<PV3f> res;
    
    foreach (const PV3f &p, listaPuntos) {
        res << PV3f(n.dot(p), b.dot(p), t.dot(p));
    }

    return res;
}
