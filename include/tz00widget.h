#ifndef TZ00WIDGET_H
#define TZ00WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


class tz00Widget : public QWidget
{
    Q_OBJECT

public:
    tz00Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
};

#endif // TZ00WIDGET_H
