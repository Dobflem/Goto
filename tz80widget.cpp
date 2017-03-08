#include "tz80widget.h"
#include "ui_tz80widget.h"
#include <QtGui>


tz80widget::tz80widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz80widget)
{
    ui->setupUi(this);
}

tz80widget::~tz80widget() {
    delete ui;
}

/*void tz80widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::black));
    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }
    painter.save();
}*/
