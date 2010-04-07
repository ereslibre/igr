#ifndef PV3F_H
#define PV3F_H

#include <GL/gl.h>

class PV3f
{
public:
    enum Tipo {
        Punto = 0,
        Vector
    };

    enum Normal {
        Izquierda = 0,
        Derecha
    };

    PV3f(Tipo tipo = Punto);
    PV3f(const PV3f &pv3f);
    PV3f(GLdouble x, GLdouble y, GLdouble z, Tipo tipo = Punto);

    GLdouble getX() const;
    GLdouble getY() const;
    GLdouble getZ() const;

    GLdouble &rX();
    GLdouble &rY();
    GLdouble &rZ();

    void setX(GLdouble x);
    void setY(GLdouble y);
    void setZ(GLdouble z);

    Tipo getTipo() const;

    GLdouble dot(const PV3f &pv3f) const;
    GLdouble mod() const;

    void normalizar();
    PV3f normaliza() const;

    PV3f operator*(const PV3f &pv3f) const;
    PV3f &operator*=(const PV3f &pv3f);
    PV3f operator*(GLdouble x) const;
    PV3f &operator*=(GLdouble x);

    PV3f operator+(const PV3f &pv3f) const;
    PV3f &operator+=(const PV3f &pv3f);

    PV3f operator-(const PV3f &pv3f) const;
    PV3f &operator-=(const PV3f &pv3f);

    bool operator==(const PV3f &rhs) const;
    bool operator!=(const PV3f &rhs) const;

private:
    GLdouble m_x;
    GLdouble m_y;
    GLdouble m_z;
    Tipo     m_tipo;
};

#endif
