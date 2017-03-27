#ifndef TZ70_H
#define TZ70_H

#include "Timezone.h"
#include "tz70widget.h"

#include <QWidget>
#include <QLCDNumber>
#include <QDial>

class TZ70 : public QObject, public Timezone
{
    Q_OBJECT
public:
    tz70widget *widget;
    TZ70():Timezone("Seventies", "seventies.jpg", "map-70s.png", "dancing-queen.mp3") {
        this->setup();
    }

    virtual bool canEnterRoom(Backpack *b);
    virtual QWidget* getTimezoneWidget();

public slots:
    void changedVolume(int);
    void clickedToken(bool);

private:
    QDial *volumeDial;
    QLCDNumber *volumeLCD;

    void setupSignalsAndSlots();
    void setup();

};

#endif // TZ70_H
