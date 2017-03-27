#include "tz00widget.h"
#include "ui_tz00widget.h"
#include <QtGui>
#include <QDebug>


tz00widget::tz00widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz00widget)
{
    ui->setupUi(this);
    ui->warningLabel->hide();
    ui->tokenButton->hide();
}

tz00widget::~tz00widget() {
    delete ui;
}

QFrame* tz00widget::getGameFrame() {
    return ui->gameFrame;
}

QPushButton* tz00widget::getTokenButton() {
    return ui->tokenButton;
}

QPushButton* tz00widget::getSubmitButton() {
    return ui->submitButton;
}

QLabel* tz00widget::getWarningLabel() {
    return ui->warningLabel;
}

bool tz00widget::getTitanicCheckBox() {
    return ui->titanicCheckBox->isChecked();
}

bool tz00widget::getNelsonCheckBox() {
    return ui->nelsonCheckBox->isChecked();
}

bool tz00widget::getMjCheckBox() {
    return ui->mjCheckBox->isChecked();
}

bool tz00widget::getIpodCheckBox() {
    return ui->ipodCheckBox->isChecked();
}

bool tz00widget::getBigBrotherCheckBox() {
    return ui->bbCheckBox->isChecked();
}

bool tz00widget::getYoutubeCheckBox() {
    return ui->youtubeCheckBox->isChecked();
}
