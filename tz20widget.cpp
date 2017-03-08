#include "tz20widget.h"
#include "ui_tz20widget.h"
#include <QtGui>


tz20widget::tz20widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz20widget)
{
    ui->setupUi(this);
}

tz20widget::~tz20widget() {
    delete ui;
}

/*void tz20widget::paintEvent(QPaintEvent *)
{
    //paint here
}*/
