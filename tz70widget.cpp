#include "tz70widget.h"
#include "ui_tz70widget.h"
#include <QtGui>


tz70widget::tz70widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz70widget)
{
    ui->setupUi(this);
}

tz70widget::~tz70widget() {
    delete ui;
}

/*void tz70widget::paintEvent(QPaintEvent *)
{
    //paint here
}*/
