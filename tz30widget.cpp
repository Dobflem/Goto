#include "tz30widget.h"
#include "ui_tz30widget.h"
#include <QtGui>
#include <QLabel>


tz30widget::tz30widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz30widget)
{
    ui->setupUi(this);
    ui->btnToken->hide();
}

tz30widget::~tz30widget() {
    delete ui;
}

ClickableLabel *tz30widget::getCapone() {
    return ui->capone;
}

void tz30widget::showToken() {
   ui->btnToken->show();
   ui->btnToken->raise();
}

bool tz30widget::tokenVisible() {
   return ui->btnToken->isVisible();
}

QPushButton *tz30widget::getToken() {
    return ui->btnToken;
}
