#ifndef VERTICENORMAL_H
#define VERTICENORMAL_H

#include "pv3f.h"

class VerticeNormal
{
public:
    VerticeNormal(const PV3f &vertice, const PV3f &normal);
    ~VerticeNormal();

    void setVertice(const PV3f &vertice);
    void setNormal(const PV3f &normal);

    PV3f vertice() const;
    PV3f normal() const;

private:
    PV3f m_vertice;
    PV3f m_normal;
};

#endif
