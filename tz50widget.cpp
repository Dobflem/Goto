#include "tz50widget.h"
#include "ui_tz50widget.h"
#include <QtGui>


tz50widget::tz50widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tz50widget)
{
    ui->setupUi(this);
    ui->imgOzColoured->hide();
}

tz50widget::~tz50widget() {
    delete ui;
}

QPushButton* tz50widget::getJunkFood() {
    return ui->junkFoodButton;
}

QSlider* tz50widget::getSliderR() {
    return ui->sliderR;
}

QSlider* tz50widget::getSliderG() {
    return ui->sliderG;
}

QSlider* tz50widget::getSliderB() {
    return ui->sliderB;
}

QLabel* tz50widget::getColouredOz() {
    return ui->imgOzColoured;
}
