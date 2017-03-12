#include "tz40widget.h"
#include "ui_tz40widget.h"
#include <QtGui>


tz40widget::tz40widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz40widget)
{
    ui->setupUi(this);
}

tz40widget::~tz40widget() {
    delete ui;
}

void tz40widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPixmap hitler = QPixmap(":/hitler.jpg");
    painter.drawPixmap(300, 300, 300, 300, hitler);
}
