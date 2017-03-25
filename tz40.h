#include "Timezone.h"
#include "tz40widget.h"
#include <QWidget>
#include <QThread>

#ifndef TZ40_H
#define TZ40_H


class TZ40 : public QThread, public Timezone {
    Q_OBJECT

public:
    tz40widget *widget;
    TZ40():Timezone("Fourties", "fourties.jpg", "map-40s.png", "1940-swing.mp3")
    {
        widget = new tz40widget();
        tokenRecieved = false;
        QObject::connect(widget->getJoint(), SIGNAL(clicked()), this, SLOT(jointButtonPressed()));
        QObject::connect(widget->getSubmitButton(), SIGNAL(clicked()), this, SLOT(submitButtonPressed()));
        QObject::connect(widget->getCloseButton(), SIGNAL(clicked()), this, SLOT(closeButtonPressed()));
        QObject::connect(widget->getStartButton(), SIGNAL(clicked()), this, SLOT(startButtonPressed()));
         QObject::connect(widget->getTokenButton(), SIGNAL(clicked()), this, SLOT(tokenButtonPressed()));
        QObject::connect(widget->getSlider(1), SIGNAL(valueChanged(int)), this, SLOT(slinkySliderValueChanged(int)));
        QObject::connect(widget->getSlider(2), SIGNAL(valueChanged(int)), this, SLOT(bandAidSliderValueChanged(int)));
        QObject::connect(widget->getSlider(3), SIGNAL(valueChanged(int)), this, SLOT(jeepSliderValueChanged(int)));
        QObject::connect(widget->getSlider(4), SIGNAL(valueChanged(int)), this, SLOT(barbieSliderValueChanged(int)));
        QObject::connect(widget->getSlider(5), SIGNAL(valueChanged(int)), this, SLOT(microwaveSliderValueChanged(int)));
    }

    //Virtual
    void enter(Backpack* b);
    bool canEnterRoom(Backpack *b);
    QWidget* getTimezoneWidget();
    void leave();

private:
    bool tokenRecieved;
    void changeLabelGeometry(QLabel*, int);
    int getImageXValue(int);
    bool sliderAnswersCorrect();
    void displayInfo();
    void displayAlreadyPassed();


public slots:
   void jointButtonPressed();
   void submitButtonPressed();
   void startButtonPressed();
   void closeButtonPressed();
   void tokenButtonPressed();
   void slinkySliderValueChanged(int);
   void barbieSliderValueChanged(int);
   void jeepSliderValueChanged(int);
   void bandAidSliderValueChanged(int);
   void microwaveSliderValueChanged(int);
};

#endif // TZ40_H
