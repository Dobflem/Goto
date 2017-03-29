#include "tz40widget.h"
#include "ui_tz40widget.h"

tz40widget::tz40widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz40widget)
{
    ui->setupUi(this);
    ui->incorrectWarning->hide();
    ui->gameFrame->hide();
    ui->tokenButton->hide();
}

tz40widget::~tz40widget() {
    delete ui;
}

QPushButton* tz40widget::getJoint() {
    return ui->jointButton;
}

QPushButton* tz40widget::getSubmitButton() {
    return ui->submitButton;
}

QPushButton* tz40widget::getCloseButton() {
    return ui->closeButton;
}

QPushButton* tz40widget::getStartButton() {
    return ui->startButton;
}

QPushButton* tz40widget::getTokenButton() {
    return ui->tokenButton;
}

QSlider* tz40widget::getSlider(int num) {
    switch(num) {
    case 1:
        return ui->slider1;
        break;
    case 2:
        return ui->slider2;
        break;
    case 3:
        return ui->slider3;
        break;
    case 4:
        return ui->slider4;
        break;
    case 5:
        return ui->slider5;
        break;
    }
}

QFrame* tz40widget::getGameFrame() {
    return ui->gameFrame;
}

void tz40widget::toggleGameFrame() {
    if (ui->gameFrame->isHidden()) {
        ui->gameFrame->show();
    } else {
        ui->gameFrame->hide();
    }
}

QLabel* tz40widget::getSlinky() {
    return ui->slinky;
}

QLabel* tz40widget::getMicrowave() {
    return ui->microwave;
}

QLabel* tz40widget::getJeep() {
    return ui->jeep;
}

QLabel* tz40widget::getBandAid() {
    return ui->bandAid;
}

QLabel* tz40widget::getBarbie() {
    return ui->barbie;
}

QLabel* tz40widget::getWarningLabel() {
    return ui->incorrectWarning;
}
