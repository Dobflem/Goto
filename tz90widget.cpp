#include "tz90widget.h"
#include "ui_tz90widget.h"

#include <QtGui>
#include <QPainter>
#include <QPushButton>
#include "clickablelabel.h"


tz90widget::tz90widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz90widget)
{
    ui->setupUi(this);
    ui->btnTokenTransparent->hide();
    ui->btnTokenTransparent->setAttribute(Qt::WA_TranslucentBackground);
}

tz90widget::~tz90widget() {

    delete ui;
}

QPushButton *tz90widget::getToken() const {
    return ui->btnToken;
}

ClickableLabel *tz90widget::getTokenTransparent() const {
    return ui->btnTokenTransparent;
}
