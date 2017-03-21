#include "tz40widget.h"
#include "ui_tz40widget.h"
#include <QtGui>


tz40widget::tz40widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz40widget)
{
    ui->setupUi(this);
}

tz40widget::~tz40widget() {
    delete ui;
}

QPushButton* tz40widget::getJoint() {
    return ui->jointButton;
}
