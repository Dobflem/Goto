#include "include/tz90widget.h"
#include "ui_tz90widget.h"
#include <QtGui>


tz90widget::tz90widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz90widget)
{
    ui->setupUi(this);
}

tz90widget::~tz90widget() {

    delete ui;
}

/*void tz90widget::paintEvent(QPaintEvent *)
{
    //paint here
}*/
