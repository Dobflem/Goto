#include "tz50.h"

bool TZ50::canEnterRoom(Backpack *b) {
    return (b->hasItem(50));
}

QWidget* TZ50::getTimezoneWidget() {
    return widget;
}

void TZ50::enter(Backpack* b) {
    this->setBackpack(b);
    this->getInfoMessage()->setMessage("I bought this coloured TV yesterday but I can't get the thing to work! Help me find a good signal!");
}

void TZ50::leave() {
    qDebug() << "Leaving";
    // Timezone::leave();
}

void TZ50::setup() {
    this->widget = new tz50widget();
    this->sliderR = this->widget->getSliderR();
    this->sliderG = this->widget->getSliderG();
    this->sliderB = this->widget->getSliderB();
    this->r = this->sliderR->value();
    this->g = this->sliderG->value();
    this->b = this->sliderB->value();
    this->signal = 0;
    this->setupSignalsAndSlots();
}

void TZ50::junkFoodButtonPressed() {
    this->widget->getJunkFood()->hide();
    this->getBackpack()->addItem(new Item(51, "Junk Food"));
}

void TZ50::calculateSignal() {
    double r = (this->r > 27) ? ((27.0 / this->r) * 100) : ((this->r / 27) * 100);
    double g = (this->g > 83) ? ((83.0 / this->g) * 100) : ((this->g / 83) * 100);
    double b = (this->b > 65) ? ((65.0 / this->b) * 100) : ((this->b / 65) * 100);

    this->signal = (r + g + b) / 3;

    QString msg = "Signal Strength: " + QString::number(this->signal);
    this->getInfoMessage()->setMessage(msg);
    this->widget->getColouredOz()->hide();
    if (this->signal == 100) this->widget->getColouredOz()->show();
}

void TZ50::checkSignalStrength() {
    if ((this->getBackpack()->hasItem(60)) && (this->signal != 100)) {
        this->getInfoMessage()->setMessage("Why would you change the signal! It was working!");
    } else if ((this->signal == 100) && (!this->getBackpack()->hasItem(60))) {
        this->widget->getToken()->show();
        this->widget->getColouredOz()->show();
        this->getInfoMessage()->setMessage("Finally, the TVs fixed! I was thinking you might of had the brain of the scarecrow for a minute! Here, take this token!");
    }
}

void TZ50::sliderRChanged(int val) {
    this->r = val; // Coercion
    this->calculateSignal();
}

void TZ50::sliderGChanged(int val) {
    this->g = val; // Coercion
    this->calculateSignal();
}

void TZ50::sliderBChanged(int val) {
    this->b = val;
    this->calculateSignal();
}

void TZ50::clickedToken() {
    this->getBackpack()->addItem(new Item(60, "60s Token"));
    this->widget->getToken()->hide();
}

void TZ50::setupSignalsAndSlots() {
    QObject::connect(this->widget->getJunkFood(), SIGNAL(clicked()), this, SLOT(junkFoodButtonPressed()));
    QObject::connect(this->sliderR, SIGNAL(valueChanged(int)), this, SLOT(sliderRChanged(int)));
    QObject::connect(this->sliderG, SIGNAL(valueChanged(int)), this, SLOT(sliderGChanged(int)));
    QObject::connect(this->sliderB, SIGNAL(valueChanged(int)), this, SLOT(sliderBChanged(int)));
    QObject::connect(this->sliderR, SIGNAL(sliderReleased()), this, SLOT(checkSignalStrength()));
    QObject::connect(this->sliderG, SIGNAL(sliderReleased()), this, SLOT(checkSignalStrength()));
    QObject::connect(this->sliderB, SIGNAL(sliderReleased()), this, SLOT(checkSignalStrength()));
    QObject::connect(this->widget->getToken(), SIGNAL(clicked(bool)), this, SLOT(clickedToken()));
}
