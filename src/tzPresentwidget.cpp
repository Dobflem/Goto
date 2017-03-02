#include "include/tzPresentWidget.h"
#include <QtGui>


tzPresentWidget::tzPresentWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Present"));
}

void tzPresentWidget::paintEvent(QPaintEvent *)
{
    //paint here
}
