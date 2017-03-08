#include "include/tz00widget.h"
#include "ui_tz00widget.h"
#include <QtGui>


tz00widget::tz00widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz00widget)
{
    ui->setupUi(this);
}

tz00widget::~tz00widget() {
    delete ui;
}

/*void tz00widget::paintEvent(QPaintEvent *)
{
    //paint here
}*/
