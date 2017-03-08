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

/*void tz50widget::paintEvent(QPaintEvent *)
{
   // QPainter painter(this);
    //painter.setBrush(QBrush(Qt::black));
    //painter.drawLine(88, 0, 96, 0);
    //painter.save();
}*/
