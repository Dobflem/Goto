#include "tz40.h"

bool TZ40::canEnterRoom(Backpack* b) {
    return (b->hasItem(40));
}

QWidget* TZ40::getTimezoneWidget() {
    return widget;
}

void TZ40::enter(Backpack* b) {
    this->setBackpack(b);
    displayInfo();
}

void TZ40::setup() {
    QObject::connect(widget->getJoint(), SIGNAL(clicked()), this, SLOT(jointButtonPressed()));
    QObject::connect(widget->getSubmitButton(), SIGNAL(clicked()), this, SLOT(submitButtonPressed()));
    QObject::connect(widget->getCloseButton(), SIGNAL(clicked()), this, SLOT(closeButtonPressed()));
    QObject::connect(widget->getStartButton(), SIGNAL(clicked()), this, SLOT(startButtonPressed()));
    QObject::connect(widget->getTokenButton(), SIGNAL(clicked()), this, SLOT(tokenButtonPressed()));
    QObject::connect(widget->getSlider(1), SIGNAL(valueChanged(int)), this, SLOT(slinkySliderValueChanged(int)));
    QObject::connect(widget->getSlider(2), SIGNAL(valueChanged(int)), this, SLOT(bandAidSliderValueChanged(int)));
    QObject::connect(widget->getSlider(3), SIGNAL(valueChanged(int)), this, SLOT(jeepSliderValueChanged(int)));
    QObject::connect(widget->getSlider(4), SIGNAL(valueChanged(int)), this, SLOT(barbieSliderValueChanged(int)));
    QObject::connect(widget->getSlider(5), SIGNAL(valueChanged(int)), this, SLOT(microwaveSliderValueChanged(int)));
}

void TZ40::displayInfo() {
    if (this->tokenRecieved) {
        displayAlreadyPassed();
    } else {
        Timezone::getInfoMessage()->setMessage("Welcome to the 40s. Move the items into the correct era they were invented in to pass this level");
    }
}

void TZ40::displayAlreadyPassed() {
    Timezone::getInfoMessage()->setMessage("You have passed this level. Continue through the timezones to make it to the present");
}

void TZ40::jointButtonPressed() {
    this->widget->getJoint()->hide();
    this->getBackpack()->addItem(new Item(41, "Joint"));
}

void TZ40::closeButtonPressed() {
    this->widget->getStartButton()->show();
    this->widget->toggleGameFrame();
}

void TZ40::startButtonPressed() {
    this->widget->toggleGameFrame();
    this->widget->getStartButton()->hide();
}

void TZ40::submitButtonPressed() {
    if (sliderAnswersCorrect()) {
        this->widget->toggleGameFrame();
        this->widget->getStartButton()->hide();
        this->widget->getTokenButton()->show();
        Timezone::getInfoMessage()->setMessage("Congratulations. You have passed this level. Please take your 50s timezone token.");
    } else {
        this->widget->getWarningLabel()->show();
        QTimer::singleShot(5000, this->widget->getWarningLabel(), &QLabel::hide);
    }
}

void TZ40::tokenButtonPressed() {
    this->tokenRecieved = true;
    this->widget->getTokenButton()->hide();

    displayAlreadyPassed();
    this->getBackpack()->addItem(new Item(50, "50s Token"));
}

bool TZ40::sliderAnswersCorrect() {
    return (EQUAL(widget->getSlider(1)->value(), this->answer1) &&
            EQUAL(widget->getSlider(2)->value(), this->answer2) &&
            EQUAL(widget->getSlider(3)->value(), this->answer3) &&
            EQUAL(widget->getSlider(4)->value(), this->answer4) &&
            EQUAL(widget->getSlider(5)->value(), this->answer5));
}

int TZ40::getImageXValue(const int value) {
    int returnVal;
    switch(value) {
        case 0:
            returnVal = 100;
            break;
        case 1:
            returnVal = 300;
            break;
        case 2:
            returnVal = 500;
            break;
    }
    return returnVal;
}

void TZ40::changeLabelGeometry(QLabel* label, const int value) {
    int x = getImageXValue(value);
    int y = label->geometry().y();
    label->setGeometry(x, y, label->width(), label->height());
}

void TZ40::slinkySliderValueChanged(const int value) {
    QLabel* slinky = this->widget->getSlinky();
    changeLabelGeometry(slinky, value);
}

void TZ40::barbieSliderValueChanged(const int value) {
    QLabel* barbie = this->widget->getBarbie();
    changeLabelGeometry(barbie, value);
}

void TZ40::jeepSliderValueChanged(const int value) {
    QLabel* jeep = this->widget->getJeep();
    changeLabelGeometry(jeep, value);
}

void TZ40::bandAidSliderValueChanged(const int value) {
    QLabel* bandAid = this->widget->getBandAid();
    changeLabelGeometry(bandAid, value);
}

void TZ40::microwaveSliderValueChanged(const int value) {
    QLabel* microwave = this->widget->getMicrowave();
    changeLabelGeometry(microwave, value);
}
