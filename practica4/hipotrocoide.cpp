#include "hipotrocoide.h"

#include <math.h>
#include <boost/math/common_factor.hpp>

Hipotrocoide::Hipotrocoide()
    : m_a(14)
    , m_b(8)
    , m_c(4)
{
}

Hipotrocoide::~Hipotrocoide()
{
}

void Hipotrocoide::dibuja()
{
    const int numVueltas = (m_b / boost::math::gcd(m_a, m_b)) * 100.0;
    const GLdouble stepSize = 2.0 * M_PI / 100.0;
    GLdouble currStepSize = 0;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(0, 0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    int numAristas = 0;
    for (int i = 0; i <= numVueltas; ++i) {
        //
        // C'(t)
        // X = -(a - b) * sin(t) - c * sin(t * (a - b)) / b) * (a - b) / b
        // Y = 0
        // Z = (a - b) * cos(t) + c * cos(t * (a - b)) / b) * (a - b) / b
        //
        // T(t) = C'(t) / || C'(t) ||
        //
        // C''(t)
        // X = -(a - b) * cos(t) - c * cos(t * (a - b) / b) * (a - b) ^ 2 / b ^ 2
        // Y = 0
        // Z = -(a - b) * sin(t) - c * sin(t * (a - b) / b) * (a - b) ^ 2 / b ^ 2
        //
        // C'(t) X C''(t)
        // X = 0
        // Y = -(a - b)^2 * (cos(t) * b * c * cos(t * (a - b) / b) * a + b^3 + sin(t) * b * c * sin(t * (a - b) / b) * a + c^2 * a - c^2 * b) / b^3
        // Z = 0
        //
        glVertex3f((m_a - m_b) * cos(currStepSize) + m_c * cos(currStepSize * (m_a - m_b) / m_b),
                   0,
                   (m_a - m_b) * sin(currStepSize) - m_c * sin(currStepSize * (m_a - m_b) / m_b));
        currStepSize += stepSize;
    }
    glEnd();
}

PV3f Hipotrocoide::derivada1(GLdouble t) const
{
    PV3f res(PV3f::Vector);
    res.setX(-(m_a - m_b) * sin(t) - m_c * sin(t * (m_a - m_b) / m_b) * (m_a - m_b) / m_b);
    res.setY(0);
    res.setZ((m_a - m_b) * cos(t) - m_c * cos(t * (m_a - m_b) / m_b) * (m_a - m_b) / m_b);

    return res;
}

PV3f Hipotrocoide::derivada2(GLdouble t) const
{
    PV3f res(PV3f::Vector);
    res.setX(-(m_a - m_b) * cos(t) - m_c * cos(t * (m_a - m_b) / m_b) * (m_a - m_b) * (m_a - m_b) / m_b * m_b);
    res.setY(0);
    res.setZ(-(m_a - m_b) * sin(t) + m_c * sin(t * (m_a - m_b) / m_b) * (m_a - m_b) * (m_a - m_b) / m_b * m_b);

    return res;
}
