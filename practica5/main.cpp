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
    v.setCentralWidget(escena);
    QDockWidget *dock = new QDockWidget(&v);
    dock->setWidget(widgetParametrico);
    v.addDockWidget(Qt::RightDockWidgetArea, dock);
    v.show();
    return app.exec();
}
