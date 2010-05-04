#include <QtGui/QApplication>
#include <QtGui/QMainWindow>
#include <QtGui/QDockWidget>

#include "escena.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QMainWindow v;
    Escena *escena = new Escena(&v);
    v.setCentralWidget(escena);
    v.show();
    return app.exec();
}
