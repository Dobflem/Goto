#include "tz60widget.h"
#include "ui_tz60widget.h"
#include <QtGui>


tz60widget::tz60widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz60widget)
{
    ui->setupUi(this);
    ui->nextButton->setArrowType(Qt::RightArrow);
    ui->foodOptions->hide();
    ui->giveHippieFoodButton->hide();
}

tz60widget::~tz60widget() {
    delete ui;
}

void tz60widget::hideSpeechBubble() {
    ui->speechBubble->hide();
}

void tz60widget::showSpeechBubble() {
    ui->speechBubble->show();
}

void tz60widget::hideNoFoodWarning() {
    ui->noFoodWarning->hide();
    ui->giveHippieFoodButton->show();
}

void tz60widget::showNoFoodWarning() {
    ui->noFoodWarning->show();
    ui->giveHippieFoodButton->hide();
}

void tz60widget::hideNoJointWarning() {
    ui->noJointWarning->hide();
    ui->giveHippieJointButton->show();
}

void tz60widget::showNoJointWarning() {
    ui->noJointWarning->show();
    ui->giveHippieJointButton->hide();
}

void tz60widget::hideNextArrow() {
    ui->nextButton->hide();
}

void tz60widget::showNextArrow() {
    ui->nextButton->show();
}

void tz60widget::showFoodOptions() {
    ui->foodOptions->show();
}

void tz60widget::hideFoodOptions() {
    ui->foodOptions->hide();
}

void tz60widget::showJointOptions() {
    ui->jointOptions->show();
}

void tz60widget::hideJointOptions() {
    ui->jointOptions->hide();
}

void tz60widget::setSpeechBubbleText(QString text) {
    ui->speechBubbleText->setText(text);
}

QPushButton* tz60widget::getTokenButton() {
    return ui->tokenButton;
}

QPushButton* tz60widget::getStartConvoButton() {
    return ui->startConvoButton;
}

QPushButton* tz60widget::getGiveHippieFoodButton() {
    return ui->giveHippieFoodButton;
}

QPushButton* tz60widget::getGiveHippieJointButton() {
    return ui->giveHippieJointButton;
}

QToolButton* tz60widget::getNextButton() {
    return ui->nextButton;
}

void tz60widget::swapHippieLabels() {
    if (ui->hippie1_label->isHidden()) {
        ui->hippie1_label->show();
        ui->hippie2_label->hide();
    } else {
        ui->hippie2_label->show();
        ui->hippie1_label->hide();
    }
}
