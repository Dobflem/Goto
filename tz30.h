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
        this->playing = false;
        this->score = 0;
        this->widget = new tz30widget();
        QThread::connect(widget->getCapone(), SIGNAL(clicked()), this, SLOT(caughtCapone()));
        QObject::connect(widget->getToken(), SIGNAL(clicked()), this, SLOT(tokenButtonPressed()));

        QObject::connect(this, SIGNAL(caponeXYchanged(int, int)), this->widget, SLOT(caponeGeometoryChanged(int, int)));
        QObject::connect(this, SIGNAL(caponeToggle()), this->widget, SLOT(toggleCapone()));
    }

    virtual bool canEnterRoom(Backpack *b);
    QWidget* getTimezoneWidget();
    virtual void enter(Backpack *b = NULL);
    void leave();

private:
    bool playing;
    int score;
    void startPlaying();
    void stopPlaying();

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
