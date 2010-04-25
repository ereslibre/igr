#ifndef HIPOTROCOIDE_H
#define HIPOTROCOIDE_H

#include "malla.h"
#include "pv3f.h"
#include "cara.h"
#include "coche.h"

#include <QtCore/QList>

#include <GL/gl.h>
#include <GL/glu.h>

class Hipotrocoide
    : public Malla
{
public:
    Hipotrocoide();
    virtual ~Hipotrocoide();

    void dibuja(GLdouble t, bool arandel);
    void recalcular();

    void setWireframe(bool wireframe);
    bool wireframe() const;

    const GLdouble *frenet() const;

    void setA(int value);
    void setB(int value);
    void setC(int value);
    void setNP(int value);
    void setNQ(int value);

private:
    PV3f derivada1(GLdouble t) const;
    PV3f derivada2(GLdouble t) const;

private:
    bool m_wireframe;
    int m_a;
    int m_b;
    int m_c;
    int m_np;
    int m_nq;
    GLdouble m_mFrenet[16];
    QList<Cara> m_listaCaras;
    QList<PV3f> m_puntosCursor;
};

#endif
