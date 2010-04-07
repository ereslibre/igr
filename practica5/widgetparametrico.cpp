#include "widgetparametrico.h"

#include <QtGui/QSpinBox>
#include <QtGui/QFormLayout>

WidgetParametrico::WidgetParametrico(QWidget *parent)
    : QWidget(parent)
{
    QFormLayout *layout = new QFormLayout;

    QSpinBox *a = new QSpinBox(this);
    QSpinBox *b = new QSpinBox(this);
    QSpinBox *c = new QSpinBox(this);
    QSpinBox *np = new QSpinBox(this);
    QSpinBox *nq = new QSpinBox(this);

    a->setRange(1, 1000);
    a->setValue(14);
    b->setRange(1, 1000);
    b->setValue(8);
    c->setRange(1, 1000);
    c->setValue(4);
    np->setRange(1, 1000);
    np->setValue(20);
    nq->setRange(1, 1000);
    nq->setValue(100);

    layout->addRow("a", a);
    layout->addRow("b", b);
    layout->addRow("c", c);
    layout->addRow("np", np);
    layout->addRow("nq", nq);

    connect(a, SIGNAL(valueChanged(int)), this, SIGNAL(aChanged(int)));
    connect(b, SIGNAL(valueChanged(int)), this, SIGNAL(bChanged(int)));
    connect(c, SIGNAL(valueChanged(int)), this, SIGNAL(cChanged(int)));
    connect(np, SIGNAL(valueChanged(int)), this, SIGNAL(npChanged(int)));
    connect(nq, SIGNAL(valueChanged(int)), this, SIGNAL(nqChanged(int)));

    setLayout(layout);
}

WidgetParametrico::~WidgetParametrico()
{
}

#include "widgetparametrico.moc"
