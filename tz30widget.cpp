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

void tz30widget::caponeGeometoryChanged(int x, int y) {
    int capone_width = getCapone()->width();
    int capone_height = getCapone()->height();

    qDebug() << "Changing capone geometry";
    ui->capone->setGeometry(x , y, capone_width, capone_height);
}

void tz30widget::toggleCapone() {
    ClickableLabel* capone = getCapone();

    if (capone->isHidden()) {
        capone->show();
    } else {
        capone->hide();
    }
}
