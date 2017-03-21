#include "Timezone.h"
#include "tz30widget.h"
#include <QWidget>
#include <QThread>
#include <QMouseEvent>

#ifndef TZ30_H
#define TZ30_H

#include <QObject>

class TZ30 : public QThread, public Timezone
{
Q_OBJECT
public:
    tz30widget *widget;
    TZ30():Timezone("Thirties", "thirties.jpg", "map-30s.png", "roaring-30s.mp3")
    {
        widget = new tz30widget();
        QThread::connect(widget->getCapone(), SIGNAL(clicked()), this, SLOT(caughtCapone()));
    }

    virtual bool canEnterRoom(Backpack *b);
    QWidget* getTimezoneWidget();
    virtual void enter(Backpack *b = NULL);
    void leave();

private:
    bool playing = false;
    int score = 0;
    void startPlaying();
    void stopPlaying();

protected:
    void run();

private slots:
   void caughtCapone();
};

#endif // TZ30_H
