#include "include/tz00widget.h"
#include <QtGui>


tz00Widget::tz00Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("00s"));
}

void tz00Widget::paintEvent(QPaintEvent *)
{
    //paint here
}
