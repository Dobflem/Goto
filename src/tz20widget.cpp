#include "include/tz20widget.h"
#include <QtGui>


tz20Widget::tz20Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("20s"));
}

void tz20Widget::paintEvent(QPaintEvent *)
{
    //paint here
}
