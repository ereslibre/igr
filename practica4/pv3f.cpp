#include "pv3f.h"

#include <QtCore/QDebug>
#include <math.h>

PV3f::PV3f(Tipo tipo)
    : m_x(0)
    , m_y(0)
    , m_z(0)
    , m_tipo(tipo)
{
}

PV3f::PV3f(const PV3f &pv3f)
    : m_x(pv3f.m_x)
    , m_y(pv3f.m_y)
    , m_z(pv3f.m_z)
    , m_tipo(pv3f.m_tipo)
{
}

PV3f::PV3f(GLdouble x, GLdouble y, GLdouble z, Tipo tipo)
    : m_x(x)
    , m_y(y)
    , m_z(z)
    , m_tipo(tipo)
{
}

GLdouble PV3f::getX() const
{
    return m_x;
}

GLdouble PV3f::getY() const
{
    return m_y;
}

GLdouble PV3f::getZ() const
{
    return m_z;
}

GLdouble &PV3f::rX()
{
    return m_x;
}

GLdouble &PV3f::rY()
{
    return m_y;
}

GLdouble &PV3f::rZ()
{
    return m_z;
}

void PV3f::setX(GLdouble x)
{
    m_x = x;
}

void PV3f::setY(GLdouble y)
{
    m_y = y;
}

void PV3f::setZ(GLdouble z)
{
    m_z = z;
}

PV3f::Tipo PV3f::getTipo() const
{
    return m_tipo;
}

GLdouble PV3f::dot(const PV3f &pv3f) const
{
    if (m_tipo != Vector) {
        qDebug() << "!!! cuenta con PV3f ilegal en dot";
        return 0;
    }
    return m_x * pv3f.m_x + m_y * pv3f.m_y + m_z * pv3f.m_z;
}

GLdouble PV3f::mod() const
{
    if (m_tipo != Vector) {
        qDebug() << "!!! cuenta con PV3f ilegal en mod";
        return 0;
    }
    return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

void PV3f::normalizar()
{
    if (m_tipo != Vector) {
        qDebug() << "!!! cuenta con PV3f ilegal en normalizar";
        return;
    }
    if (m_x <= 1.0 && m_y <= 1.0 && m_z <= 1.0) {
        return;
    }
    const GLdouble c = 1 / sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
    m_x *= c;
    m_y *= c;
    m_z *= c;
}

PV3f PV3f::normaliza() const
{
    PV3f res(*this);
    res.normalizar();
    return res;
}

PV3f PV3f::operator*(const PV3f &pv3f) const
{
    PV3f res;
    if (m_tipo == Vector && pv3f.m_tipo == Vector) {
        res.setX(-(m_y * pv3f.m_z - m_z * pv3f.m_y));
        res.setY(m_x * pv3f.m_z - m_z * pv3f.m_x);
        res.setZ(-(m_x * pv3f.m_y - m_y * pv3f.m_x));
        res.m_tipo = Vector;
    } else if (m_tipo == Punto && pv3f.m_tipo == Vector) {
        res.setX(-(m_y * pv3f.m_z - m_z * pv3f.m_y));
        res.setY(m_x * pv3f.m_z - m_z * pv3f.m_x);
        res.setZ(-(m_x * pv3f.m_y - m_y * pv3f.m_x));
        res.m_tipo = Punto;
    } else {
        qDebug() << "!!! cuenta con PV3f ilegal en operator*(PV3f)";
    }
    return res;
}

PV3f &PV3f::operator*=(const PV3f &pv3f)
{
    if (m_tipo == Vector && pv3f.m_tipo == Vector) {
        m_x = -(m_y * pv3f.m_z - m_z * pv3f.m_y);
        m_y = m_x * pv3f.m_z - m_z * pv3f.m_x;
        m_z = -(m_x * pv3f.m_y - m_y * pv3f.m_x);
    } else {
        qDebug() << "!!! cuenta con PV3f ilegal en operator*(PV3f)";
    }
    return *this;
}

PV3f PV3f::operator*(GLdouble x) const
{
    PV3f res(Vector);
    if (m_tipo == Vector) {
        res.m_tipo = Vector;
        res.m_x = m_x * x;
        res.m_y = m_y * x;
        res.m_z = m_z * x;
    } else {
        qDebug() << "!!! cuenta con PV3f ilegal en operator*(GLdouble)";
    }
    return res;
}

PV3f &PV3f::operator*=(GLdouble x)
{
    if (m_tipo != Vector) {
        qDebug() << "!!! cuenta con PV3f ilegal en operator*=(GLdouble)";
        return *this;
    }
    m_x *= x;
    m_y *= x;
    m_z *= x;
    return *this;
}

PV3f PV3f::operator+(const PV3f &pv3f) const
{
    PV3f res;
    if (m_tipo == Punto && pv3f.m_tipo == Vector || m_tipo == Vector && pv3f.m_tipo == Punto) {
        res.m_tipo = Punto;
    } else if (m_tipo == Vector && pv3f.m_tipo == Vector) {
        res.m_tipo = Vector;
    } else {
        qDebug() << "!!! cuenta con PV3f ilegal en operator+(PV3f)";
        return res;
    }
    res.m_x = m_x + pv3f.m_x;
    res.m_y = m_y + pv3f.m_y;
    res.m_z = m_z + pv3f.m_z;
    return res;
}

PV3f &PV3f::operator+=(const PV3f &pv3f)
{
    if (m_tipo == Punto && pv3f.m_tipo == Vector || m_tipo == Vector && pv3f.m_tipo == Punto) {
        m_tipo = Punto;
    } else if (m_tipo == Vector && pv3f.m_tipo == Vector) {
        m_tipo = Vector;
    } else {
        qDebug() << "!!! cuenta con PV3f ilegal en operator+=(PV3f)";
        return *this;
    }
    m_x += pv3f.m_x;
    m_y += pv3f.m_y;
    m_z += pv3f.m_z;
    return *this;
}

PV3f PV3f::operator-(const PV3f &pv3f) const
{
    PV3f res;
    if (m_tipo == Punto && pv3f.m_tipo == Punto || m_tipo == Vector && pv3f.m_tipo == Vector) {
        res.m_tipo = Vector;
    } else {
        qDebug() << "!!! cuenta con PV3f ilegal en operator-(PV3f)";
        return res;
    }
    res.m_x = m_x - pv3f.m_x;
    res.m_y = m_y - pv3f.m_y;
    res.m_z = m_z - pv3f.m_z;
    return res;
}

PV3f &PV3f::operator-=(const PV3f &pv3f)
{
    if (m_tipo == Punto && pv3f.m_tipo == Punto || m_tipo == Vector && pv3f.m_tipo == Vector) {
        m_tipo = Vector;
    } else {
        qDebug() << "!!! cuenta con PV3f ilegal en operator-=(PV3f)";
        return *this;
    }
    m_x -= pv3f.m_x;
    m_y -= pv3f.m_y;
    m_z -= pv3f.m_z;
    return *this;
}

bool PV3f::operator==(const PV3f &rhs) const
{
    return m_x == rhs.m_x && m_y == rhs.m_y && m_z == rhs.m_z && m_tipo == rhs.m_tipo;
}

bool PV3f::operator!=(const PV3f &rhs) const
{
    return m_x != rhs.m_x || m_y != rhs.m_y || m_z != rhs.m_z || m_tipo != rhs.m_tipo;
}
