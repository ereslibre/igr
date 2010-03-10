#include "frenet.h"

#include <QtCore/QDebug>
#include <math.h>

QList<PV3f> Frenet::marco(const QList<PV3f> &listaPuntos, GLdouble t, int a, GLdouble b, int c)
{
//     const PV3f pc((a - b) * cos(t) + c * cos(t * (a - b) / b), 0,
//                   (a - b) * sin(t) - c * sin(t * (a - b) / b), PV3f::Punto);
    const PV3f pc(cos(t), sin(t), ((GLdouble) b) * t, PV3f::Punto);
    qDebug() << "b * t" << ((GLdouble) b) * t;
    const PV3f dpc = derivada1(t, a, b, c);
    const PV3f ddpc = derivada2(t, a, b, c);
    const PV3f vt = (dpc * (1.0 / dpc.mod())).normaliza();
    const PV3f vb = ((dpc * ddpc) * (1.0 / (dpc * ddpc).mod())).normaliza();
    const PV3f vn = (((dpc * ddpc) * dpc) * (1.0 / ((dpc * ddpc) * dpc).mod())).normaliza();

    prueba(pc,vb,vt,vn);
    
    
    //return multMatriz(listaPuntos, vn, vb, vt);
    return QList<PV3f>();
}

PV3f Frenet::prueba(const PV3f &p, const PV3f &b, const PV3f &t, const PV3f &n)
{
    glBegin(GL_LINES);
    glColor4f(1.0,0.0,0.0,1.0);
    glVertex3d(p.getX(),p.getY(),p.getZ());
    PV3f aux = p * (b*2.0);
    glVertex3d(aux.getX(),aux.getY(),aux.getZ());

    glColor4f(0.0,1.0,0.0,1.0);
    glVertex3d(p.getX(),p.getY(),p.getZ());
    aux = p * (n*2.0);
    glVertex3d(aux.getX(),aux.getY(),aux.getZ());
    
    glColor4f(0.0,0.0,1.0,1.0);
    glVertex3d(p.getX(),p.getY(),p.getZ());
    aux = p * (t*2.0);
    glVertex3d(aux.getX(),aux.getY(),aux.getZ());
    glEnd();
}

PV3f Frenet::derivada1(GLdouble t, int a, int b, int c)
{
    PV3f res(PV3f::Vector);
    res.setX(-sin(t));
    res.setY(cos(t));
    res.setZ(b);

//     PV3f res(PV3f::Vector);
//     res.setX(-(a - b) * sin(t) - c * sin(t * (a - b) / b) * (a - b) / b);
//     res.setY(0);
//     res.setZ((a - b) * cos(t) - c * cos(t * (a - b) / b) * (a - b) / b);

    return res;
}

PV3f Frenet::derivada2(GLdouble t, int a, int b, int c)
{
    PV3f res(PV3f::Vector);
    res.setX(-cos(t));
    res.setY(-sin(t));
    res.setZ(0);

//     PV3f res(PV3f::Vector);
//     res.setX(-(a - b) * cos(t) - c * cos(t * (a - b) / b) * ((a - b) * (a - b) / b * b));
//     res.setY(0);
//     res.setZ(-(a - b) * sin(t) + c * sin(t * (a - b) / b) * ((a - b) * (a - b) / b * b));

    return res;
}

QList<PV3f> Frenet::multMatriz(const QList<PV3f> &listaPuntos, const PV3f &n, const PV3f &b, const PV3f &t)
{
    QList<PV3f> res;
    
    foreach (const PV3f &p, listaPuntos) {
        res << PV3f(n.dot(p), b.dot(p), t.dot(p), PV3f::Punto);
    }

    return res;
}
