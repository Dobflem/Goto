#ifndef TZ50WIDGET_H
#define TZ50WIDGET_H

#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include <QLabel>
#include <QtGui>

namespace Ui {
class tz50widget;
}

class tz50widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz50widget(QWidget *parent = 0);
    ~tz50widget();
    QPushButton* getJunkFood() const;
    QSlider *getSliderR() const;
    QSlider *getSliderG() const;
    QSlider *getSliderB() const;
    QLabel *getColouredOz() const;
    QPushButton *getToken() const;

private:
    Ui::tz50widget *ui;
};

#endif // TZ50WIDGET_H

