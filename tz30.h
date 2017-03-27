#include "Timezone.h"
#include "tz30widget.h"
#include <QWidget>
#include <QThread>
#include <QMouseEvent>

#ifndef TZ30_H
#define TZ30_H

#include <QObject>

class TZ30 : public QThread, public Timezone  {
Q_OBJECT

public:
    tz30widget *widget;
    TZ30():Timezone("Thirties", "thirties.jpg", "map-30s.png", "roaring-30s.mp3")
    {
        this->setup();
    }

    virtual bool canEnterRoom(Backpack *b);
    virtual QWidget* getTimezoneWidget();
    virtual void enter(Backpack *b = NULL);
    virtual void leave();

private:
    bool playing;
    int score;
    void startPlaying();
    void stopPlaying();
    void setup();

protected:
    void run();

private slots:
   void caughtCapone();
   void tokenButtonPressed();

signals:
    void caponeXYchanged(int x, int y);
    void caponeToggle();
};

#endif // TZ30_H
