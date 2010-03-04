#include "hipotrocoide.h"

#include <math.h>
#include <boost/math/common_factor.hpp>

Hipotrocoide::Hipotrocoide()
    : m_a(7)
    , m_b(4)
    , m_c(2)
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
        glVertex2f((m_a - m_b) * cos(currStepSize) + m_c * cos(currStepSize * (m_a - m_b) / m_b),
                   (m_a - m_b) * sin(currStepSize) - m_c * sin(currStepSize * (m_a - m_b) / m_b));
        currStepSize += stepSize;
    }
    glEnd();
}
