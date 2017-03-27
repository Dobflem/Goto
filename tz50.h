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
    TZ50():Timezone("Fifties", "fifties.jpg", "map-50s.png", "jailhouse-rock.mp3") {
        setup();
    }

    virtual void enter(Backpack* b);
    virtual bool canEnterRoom(Backpack *b);
    virtual QWidget* getTimezoneWidget();
    virtual void leave();

public slots:
   void junkFoodButtonPressed();
   void checkSignalStrength();
   void sliderRChanged(int);
   void sliderGChanged(int);
   void sliderBChanged(int);
   void clickedToken(bool);

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
