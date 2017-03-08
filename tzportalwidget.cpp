#include "tzportalwidget.h"
#include "ui_tzportalwidget.h"
#include <QtGui>


tzportalwidget::tzportalwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tzportalwidget)
{
    ui->setupUi(this);
}

tzportalwidget::~tzportalwidget() {
    delete ui;
}

/*void tzportalwidget::paintEvent(QPaintEvent *)
{
    //paint here
}*/
