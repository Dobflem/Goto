#ifndef TZ20WIDGET_H
#define TZ20WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


class tz20Widget : public QWidget
{
    Q_OBJECT

public:
    tz20Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
};

#endif // TZ20WIDGET_H
