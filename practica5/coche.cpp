#include "coche.h"
#include "lapiz.h"
#include "frenet.h"
#include "hipotrocoide.h"

#include <QtCore/QDebug>
#include <QtCore/QList>
#include <math.h>
#include <boost/math/common_factor.hpp>

Coche::Coche(Hipotrocoide *hipotrocoide)
    : m_angulo(0)
    , m_hipotrocoide(hipotrocoide)
{
    m_dis1 = gluNewQuadric();
    m_dis2 = gluNewQuadric();
    m_dis3 = gluNewQuadric();
    m_dis4 = gluNewQuadric();
    m_rue1 = gluNewQuadric();
    m_rue2 = gluNewQuadric();
    m_rue3 = gluNewQuadric();
    m_rue4 = gluNewQuadric();
}

Coche::~Coche()
{
    gluDeleteQuadric(m_dis1);
    gluDeleteQuadric(m_dis2);
    gluDeleteQuadric(m_dis3);
    gluDeleteQuadric(m_dis4);
    gluDeleteQuadric(m_rue1);
    gluDeleteQuadric(m_rue2);
    gluDeleteQuadric(m_rue3);
    gluDeleteQuadric(m_rue4);
}

void Coche::avanza()
{
    m_angulo += 10;
}

void Coche::retrocede()
{
    m_angulo -= 10;
}

void Coche::dibuja(GLdouble scale)
{
    glPushMatrix();
    //glMultMatrixd(m_hipotrocoide->frenet());
    scale = 5;
    glPushMatrix();
    glRotatef(180, 1, 0, 0);

    // Rectángulo inferior
    glPushMatrix();
    glColor3f(0.0f,1.0f,0.0f);
    dibujaRect(0.0,0.0,0.0,scale);
    glPopMatrix();

    // Rectángulo superior (cabina)
    glPushMatrix();
    glColor3f(0.0f,0.5f,0.0f);
    dibujaRect(0.0,3*scale/4,0.0,scale/2);
    glPopMatrix();

    // Ruedas
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    // Hay que trasladar la rueda, también hay que tener en cuenta 
    // el grosor de la llanta.
    glTranslatef(scale/2,-scale/2,scale/2+0.2*scale);
    glRotatef(m_angulo,0.0f,0.0f,1.0f);
    gluQuadricDrawStyle(m_rue1,GLU_FILL);
    gluCylinder(m_rue1, scale/3, scale/3, 0.2, 3, 3);

    // Tapacubos 1
    glTranslatef(0.0f, 0.0f, 0.2f);
    gluQuadricDrawStyle(m_dis1,GLU_FILL);
    gluDisk(m_dis1, 0, scale/3, 3, 3);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(-scale/2,-scale/2,scale/2+0.2*scale);
    glRotatef(m_angulo,0.0f,0.0f,1.0f);
    gluQuadricDrawStyle(m_rue2,GLU_FILL);
    gluCylinder(m_rue2, scale/3, scale/3, 0.2, 3, 3);

    // Tapacubos 2
    glTranslatef(0.0f, 0.0f, 0.2f);
    gluQuadricDrawStyle(m_dis2,GLU_FILL);
    gluDisk(m_dis2, 0, scale/3, 3, 3);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(scale/2,-scale/2,scale/2+0.2*scale);
    glRotatef(-m_angulo,0.0f,0.0f,1.0f);
    gluQuadricDrawStyle(m_rue3,GLU_FILL);
    gluCylinder(m_rue3, scale/3, scale/3, 0.2, 3, 3);

    // Tapacubos 3
    glTranslatef(0.0f, 0.0f, 0.2f);
    gluQuadricDrawStyle(m_dis3,GLU_FILL);
    gluDisk(m_dis3, 0, scale/3, 3, 3);
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(-scale/2,-scale/2,scale/2+0.2*scale);
    glRotatef(-m_angulo,0.0f,0.0f,1.0f);
    gluQuadricDrawStyle(m_rue4,GLU_FILL);
    gluCylinder(m_rue4, scale/3, scale/3, 0.2, 3, 3);

    // Tapacubos 4
    glTranslatef(0.0f, 0.0f, 0.2f);
    gluQuadricDrawStyle(m_dis4,GLU_FILL);
    gluDisk(m_dis4, 0, scale/3, 3, 3);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}

void Coche::dibujaRect(GLdouble x, GLdouble y, GLdouble z, GLdouble scale)
{
    glPushMatrix();
    glBegin(GL_POLYGON);

    /*La cara de arriba*/
    glVertex3f((-3*scale/4)+x, scale/2+y,-scale+z);//sup-izq v5
    glVertex3f((-3*scale/4)+x, scale/2+y, scale+z);//inf-izq v6
    glVertex3f(( 3*scale/4)+x, scale/2+y, scale+z);//inf-der v7
    glVertex3f(( 3*scale/4)+x, scale/2+y,-scale+z);//sup-der v8

    /*La cara de enfrente*/
    glVertex3f((-3*scale/4)+x, scale/2+y, scale+z);//sup-izq v6
    glVertex3f((-3*scale/4)+x,-scale/2+y, scale+z);//inf-izq v2
    glVertex3f(( 3*scale/4)+x,-scale/2+y, scale+z);//inf-der v3
    glVertex3f(( 3*scale/4)+x, scale/2+y, scale+z);//sup-der v7

    /*La cara derecha*/
    glVertex3f(( 3*scale/4)+x, scale/2+y, scale+z);//sup-izq v7
    glVertex3f(( 3*scale/4)+x,-scale/2+y, scale+z);//inf-izq v3
    glVertex3f(( 3*scale/4)+x,-scale/2+y,-scale+z);//inf-der v4
    glVertex3f(( 3*scale/4)+x, scale/2+y,-scale+z);//sup-der v8

    /*La cara izquierda*/
    glVertex3f((-3*scale/4)+x, scale/2+y, scale+z);//sup-izq v6
    glVertex3f((-3*scale/4)+x,-scale/2+y, scale+z);//inf-izq v2
    glVertex3f((-3*scale/4)+x,-scale/2+y,-scale+z);//inf-der v1
    glVertex3f((-3*scale/4)+x, scale/2+y,-scale+z);//sup-der v5
    
    /*La cara de debajo*/
    glVertex3f((-3*scale/4)+x,-scale/2+y,-scale+z);//sup-izq v1
    glVertex3f((-3*scale/4)+x,-scale/2+y, scale+z);//inf-izq v2
    glVertex3f(( 3*scale/4)+x,-scale/2+y, scale+z);//inf-der v3
    glVertex3f(( 3*scale/4)+x,-scale/2+y,-scale+z);//sup-der v4
    
    /*La cara de detrás*/
    glVertex3f((-3*scale/4)+x, scale/2+y,-scale+z);//sup-izq v5
    glVertex3f((-3*scale/4)+x,-scale/2+y,-scale+z);//inf-izq v1
    glVertex3f(( 3*scale/4)+x,-scale/2+y,-scale+z);//inf-der v4
    glVertex3f(( 3*scale/4)+x, scale/2+y,-scale+z);//sup-der v8
    glEnd();

    glPopMatrix();
}

void Coche::dibujaRect2(int divX, int divY, int divZ)
{
    m_numX = divX;
    m_numY = divY;
    m_numZ = divZ;

    m_numCubos = m_numX*m_numY*m_numZ;
}
