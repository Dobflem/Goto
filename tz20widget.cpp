#include "tz20widget.h"
#include "ui_tz20widget.h"

tz20widget::tz20widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz20widget)
{
    ui->setupUi(this);
}

tz20widget::~tz20widget() {
    delete ui;
}

QPushButton* tz20widget::getButton() {
    return ui->tokenButton;
}

QPushButton* tz20widget::getKeyButton() {
    return ui->keyButton;
}
