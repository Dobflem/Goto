#include "tzpresentwidget.h"
#include "ui_tzpresentwidget.h"

tzpresentwidget::tzpresentwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tzpresentwidget)
{
    ui->setupUi(this);
}

tzpresentwidget::~tzpresentwidget() {
    delete ui;
}

