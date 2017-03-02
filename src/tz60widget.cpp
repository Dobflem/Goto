#include "include/tz60widget.h"
#include <QtGui>


tz60Widget::tz60Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("60s"));
}

void tz60Widget::paintEvent(QPaintEvent *)
{
    //paint here
}
