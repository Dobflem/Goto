#include "tzportalwidget.h"
#include "ui_tzportalwidget.h"


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
