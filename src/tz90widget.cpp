#include "include/tz90widget.h"
#include <QtGui>


tz90Widget::tz90Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("90s"));
}

void tz90Widget::paintEvent(QPaintEvent *)
{
    //paint here
}
