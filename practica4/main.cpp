#include <QtGui/QApplication>
#include <QtGui/QMainWindow>
#include <QtGui/QDockWidget>

#include "escena.h"
#include "widgetparametrico.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QMainWindow v;
    Escena *escena = new Escena(&v);
    WidgetParametrico *widgetParametrico = new WidgetParametrico(&v);
    QObject::connect(widgetParametrico, SIGNAL(aChanged(int)), escena, SLOT(aChanged(int)));
    QObject::connect(widgetParametrico, SIGNAL(bChanged(int)), escena, SLOT(bChanged(int)));
    QObject::connect(widgetParametrico, SIGNAL(cChanged(int)), escena, SLOT(cChanged(int)));
    QObject::connect(widgetParametrico, SIGNAL(npChanged(int)), escena, SLOT(npChanged(int)));
    QObject::connect(widgetParametrico, SIGNAL(nqChanged(int)), escena, SLOT(nqChanged(int)));
    v.setCentralWidget(escena);
    QDockWidget *dock = new QDockWidget(&v);
    dock->setWidget(widgetParametrico);
    v.addDockWidget(Qt::RightDockWidgetArea, dock);
    v.show();
    return app.exec();
}
