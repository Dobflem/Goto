#include "Timezone.h"
#include "tz50widget.h"
#include <QWidget>
#include <QObject>
#include <QSlider>
#include <QThread>
#include <cmath>

#ifndef TZ50_H
#define TZ50_H


class TZ50 : public QObject, public Timezone {
    Q_OBJECT

public:
    tz50widget *widget;
    TZ50():Timezone("Fifties", "fifties.jpg", "map-50s.png", "jailhouse-rock.mp3"),
        widget(new tz50widget()),
        sliderR(this->widget->getSliderR()),
        sliderG(this->widget->getSliderG()),
        sliderB(this->widget->getSliderB()),
        r(this->sliderR->value()),
        g(this->sliderG->value()),
        b(this->sliderB->value()), signal(0) {
        setup();
    }

    virtual void enter(Backpack* b);
    virtual bool canEnterRoom(Backpack *b);
    virtual QWidget* getTimezoneWidget();

public slots:
   void junkFoodButtonPressed();
   void checkSignalStrength();
   void sliderRChanged(int);
   void sliderGChanged(int);
   void sliderBChanged(int);
   void clickedToken();

private:
    QSlider *sliderR;
    QSlider *sliderG;
    QSlider *sliderB;
    double r, g, b, signal;

    void setupSignalsAndSlots();
    void calculateSignal();
    void setup();
};

#endif // TZ50_H
