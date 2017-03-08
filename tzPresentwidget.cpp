#include "include/tzpresentwidget.h"
#include "ui_tzpresentwidget.h"
#include <QtGui>


tzpresentwidget::tzpresentwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tzpresentwidget)
{
    ui->setupUi(this);
}

tzpresentwidget::~tzpresentwidget() {
    delete ui;
}

/*void tzpresentwidget::paintEvent(QPaintEvent *)
{
    //paint here
}*/
