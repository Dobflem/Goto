#include "include/tz30widget.h"
#include <QtGui>


tz30Widget::tz30Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("30s"));
}

void tz30Widget::paintEvent(QPaintEvent *)
{
    //paint here
}
