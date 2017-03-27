#include "Timezone.h"
#include "tz50widget.h"
#include <QWidget>
#include <QObject>
#include <QSlider>
#include <QThread>

#ifndef TZ50_H
#define TZ50_H


class TZ50 : public QObject, public Timezone {
    Q_OBJECT

public:
    tz50widget *widget;
    TZ50():Timezone("Fifties", "fifties.jpg", "map-50s.png", "jailhouse-rock.mp3")
    {
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

    // Virtual
    void enter(Backpack* b);
    bool canEnterRoom(Backpack *b);
    QWidget* getTimezoneWidget();
    void leave();

public slots:
   void junkFoodButtonPressed();
   void sliderRChanged(int);
   void sliderGChanged(int);
   void sliderBChanged(int);
   void checkSignalStrength();

private:
    QSlider *sliderR;
    QSlider *sliderG;
    QSlider *sliderB;
    double r, g, b, signal;

    void setupSignalsAndSlots();
    void calculateSignal();
};

#endif // TZ50_H
