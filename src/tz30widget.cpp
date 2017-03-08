#include "include/tz30widget.h"
#include "ui_tz30widget.h"
#include <QtGui>


tz30widget::tz30widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz30widget)
{
    ui->setupUi(this);
}

tz30widget::~tz30widget() {
    delete ui;
}

/*void tz30widget::paintEvent(QPaintEvent *)
{
    //paint here
}*/
