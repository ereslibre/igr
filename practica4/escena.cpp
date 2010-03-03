#include "escena.h"

#include <math.h>

Escena::Escena(QWidget *parent)
    : QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
}

Escena::~Escena()
{
    makeCurrent();
}

void Escena::initializeGL()
{
}

void Escena::paintGL()
{
}
