#ifndef TZ80WIDGET_H
#define TZ80WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


class tz80Widget : public QWidget
{
    Q_OBJECT

public:
    tz80Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
};

#endif // TZ80WIDGET_H
