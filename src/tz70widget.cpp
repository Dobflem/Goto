#include "include/tz70widget.h"
#include <QtGui>


tz70Widget::tz70Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("00s"));
}

void tz70Widget::paintEvent(QPaintEvent *)
{
    //paint here
}
