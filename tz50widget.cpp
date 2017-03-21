#include "tz50widget.h"
#include "ui_tz50widget.h"
#include <QtGui>


tz50widget::tz50widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz50widget)
{
    ui->setupUi(this);
}

tz50widget::~tz50widget() {
    delete ui;
}

QPushButton* tz50widget::getJunkFood() {
    return ui->junkFoodButton;
}
