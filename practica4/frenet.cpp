#include "frenet.h"

#include <QtCore/QDebug>
#include <math.h>

QList<PV3f> Frenet::marco(const QList<PV3f> &listaPuntos, GLdouble a, GLdouble b, GLdouble c, GLdouble t)
{
    const PV3f pc((a - b) * cos(t) + c * cos(t * (a - b) / b), 0,
                  (a - b) * sin(t) - c * sin(t * (a - b) / b), PV3f::Punto);
    const PV3f dpc = derivada1(a, b, c, t);
    const PV3f ddpc = derivada2(a, b, c, t);
    const PV3f vt = (dpc * pow(dpc.mod(), -1.0)).normaliza();
    const PV3f vb = ((dpc * ddpc) * pow((dpc * ddpc).mod(), -1.0)).normaliza();
    const PV3f vn = (((dpc * ddpc) * dpc) * pow(((dpc * ddpc) * dpc).mod(), -1.0)).normaliza();

    return multMatriz(listaPuntos, vn, vb, vt, a, b, c, t);
}

PV3f Frenet::derivada1(GLdouble a, GLdouble b, GLdouble c, GLdouble t)
{
    PV3f res(PV3f::Vector);
    res.setX(-(a - b) * sin(t) - c * sin(t * (a - b) / b) * (a - b) / b);
    res.setY(0);
    res.setZ((a - b) * cos(t) - c * cos(t * (a - b) / b) * (a - b) / b);

    return res;
}

PV3f Frenet::derivada2(GLdouble a, GLdouble b, GLdouble c, GLdouble t)
{
    PV3f res(PV3f::Vector);
    res.setX(-(a - b) * cos(t) - c * cos(t * (a - b) / b) * ((a - b) * (a - b) / b * b));
    res.setY(0);
    res.setZ(-(a - b) * sin(t) + c * sin(t * (a - b) / b) * ((a - b) * (a - b) / b * b));

    return res;
}

QList<PV3f> Frenet::multMatriz(const QList<PV3f> &listaPuntos, const PV3f &vn, const PV3f &vb, const PV3f &vt, GLdouble a, GLdouble b, GLdouble c, GLdouble t)
{
    QList<PV3f> res;
    foreach (const PV3f &p, listaPuntos) {
        //NOTE: Es NECESARIO sumar a la función ORIGINAL de la curva la matriz que hemos obtenido
        //      Ver: http://en.wikipedia.org/wiki/Frenet%E2%80%93Serret_formulas#Ribbons_and_Tubes
        res << PV3f((a - b) * cos(t) + c * cos(t * (a - b) / b), 0,
                    (a - b) * sin(t) - c * sin(t * (a - b) / b)) +
               PV3f(vn.dot(p), vb.dot(p), vt.dot(p), PV3f::Vector);
    }
    return res;
}
