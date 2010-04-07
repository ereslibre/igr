#ifndef WIDGETPARAMETRICO_H
#define WIDGETPARAMETRICO_H

#include <QtGui/QWidget>

class WidgetParametrico
    : public QWidget
{
    Q_OBJECT

public:
    WidgetParametrico(QWidget *parent = 0);
    ~WidgetParametrico();

Q_SIGNALS:
    void aChanged(int value);
    void bChanged(int value);
    void cChanged(int value);
    void npChanged(int value);
    void nqChanged(int value);
};

#endif

