#include "include/tz60widget.h"
#include "ui_tz60widget.h"
#include <QtGui>


tz60widget::tz60widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz60widget)
{
    ui->setupUi(this);
}

tz60widget::~tz60widget() {
    delete ui;
}


/*void tz60widget::paintEvent(QPaintEvent *)
{
    //paint here
}*/
