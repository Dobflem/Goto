#include "include/tz50widget.h"
#include <QtGui>


tz50Widget::tz50Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("50s"));
}

void tz50Widget::paintEvent(QPaintEvent *)
{
   // QPainter painter(this);
    //painter.setBrush(QBrush(Qt::black));
    //painter.drawLine(88, 0, 96, 0);
    //painter.save();
}
