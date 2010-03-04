#ifndef CARA_H
#define CARA_H

#include <QtCore/QList>

#include "pv3f.h"

class Cara
{
public:
    Cara(const QList<PV3f> &vertices);
    virtual ~Cara();

    QList<PV3f> listaVertices() const;

    PV3f normal() const;

private:
    void newell();
    int suc(int i) const;

private:
    QList<PV3f> m_vertices;
    PV3f        m_normal;
};

#endif
