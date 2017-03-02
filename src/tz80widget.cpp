#include "include/tz80widget.h"
#include <QtGui>


tz80Widget::tz80Widget(QWidget *parent)
    : QWidget(parent)
{

}

void tz80Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::black));
    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }
    painter.save();
}
