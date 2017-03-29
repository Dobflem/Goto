#include "tz50widget.h"
#include "ui_tz50widget.h"

tz50widget::tz50widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz50widget)
{
    ui->setupUi(this);
    ui->imgOzColoured->hide();
    ui->btnToken->hide();
}

tz50widget::~tz50widget() {
    delete ui;
}

QPushButton* tz50widget::getJunkFood() const {
    return ui->junkFoodButton;
}

QSlider* tz50widget::getSliderR() const {
    return ui->sliderR;
}

QSlider* tz50widget::getSliderG() const {
    return ui->sliderG;
}

QSlider* tz50widget::getSliderB() const {
    return ui->sliderB;
}

QLabel* tz50widget::getColouredOz() const {
    return ui->imgOzColoured;
}

QPushButton *tz50widget::getToken() const {
    return ui->btnToken;
}
