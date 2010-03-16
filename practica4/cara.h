#ifndef CARA_H
#define CARA_H

#include <QtCore/QList>

#include "pv3f.h"

class Cara
{
public:
    enum DrawType {
        Wireframe = 0,
        Solid
    };

    Cara();
    Cara(const QList<PV3f> &vertices);
    virtual ~Cara();

    void dibuja(DrawType drawType) const;

    QList<PV3f> vertices() const;

private:
    void newell();
    int suc(int i) const;

private:
    QList<PV3f> m_vertices;
    PV3f        m_normal;
};

#endif
