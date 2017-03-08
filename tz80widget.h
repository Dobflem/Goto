#ifndef TZ80WIDGET_H
#define TZ80WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


namespace Ui {
class tz80widget;
}

class tz80widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz80widget(QWidget *parent = 0);
    ~tz80widget();
    //void paintEvent(QPaintEvent *event);

private:
    Ui::tz80widget *ui;
};

#endif // TZ80WIDGET_H

