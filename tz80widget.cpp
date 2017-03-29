#include "tz80widget.h"
#include "ui_tz80widget.h"

tz80widget::tz80widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz80widget)
{
    ui->setupUi(this);
}

tz80widget::~tz80widget() {
    delete ui;
}

QPushButton* tz80widget::getSubmitButton() {
    return ui->submitButton;
}

QPushButton* tz80widget::getUnlockQuestionButton() {
    return ui->UnlockQuestionButton;
}

QComboBox* tz80widget::getQ1ComboBox() {
    return ui->question1_comboBox;
}

QComboBox* tz80widget::getQ2ComboBox() {
    return ui->question2_comboBox;
}

QComboBox* tz80widget::getQ3ComboBox() {
    return ui->question3_comboBox;
}

QComboBox* tz80widget::getQ4ComboBox() {
    return ui->question4_comboBox;
}

QLabel* tz80widget::getWarningLabel() {
    return ui->warning_label;
}

QFrame* tz80widget::getQuizFrame() {
    return ui->quiz_frame;
}

QPushButton* tz80widget::getTokenButton() {
    return ui->tokenButton;
}

QPushButton* tz80widget::getStartButton() {
    return ui->startButton;
}

QPushButton* tz80widget::getCloseButton() {
    return ui->closeButton;
}

QFrame* tz80widget::getLockedQuestionFrame() {
    return ui->questionlocked_frame;
}
