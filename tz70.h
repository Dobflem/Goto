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
    TZ70():Timezone("Seventies", "seventies.jpg", "map-70s.png", "dancing-queen.mp3"),
    widget(new tz70widget()), volumeDial(this->widget->getVolumeDial()), volumeLCD(this->widget->getVolumeLCD()){
        this->setupSignalsAndSlots();
    }

    virtual bool canEnterRoom(Backpack *b);
    virtual QWidget* getTimezoneWidget();
    virtual void enter(Backpack* b);

public slots:
    void changedVolume(int);
    void clickedToken();

private:
    QDial *volumeDial;
    QLCDNumber *volumeLCD;

    void setupSignalsAndSlots();

};

#endif // TZ70_H
