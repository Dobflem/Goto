#include "tz70widget.h"
#include "ui_tz70widget.h"

#include <QtGui>
#include <QDial>
#include <QLCDNumber>


tz70widget::tz70widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz70widget)
{
    ui->setupUi(this);
}

tz70widget::~tz70widget() {
    delete ui;
}

QDial *tz70widget::getVolumeDial() const {
    return ui->dialVolume;
}

QLCDNumber *tz70widget::getVolumeLCD() const {
    return ui->lcdVolume;
}
