#ifndef TZ30WIDGET_H
#define TZ30WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


class tz30Widget : public QWidget
{
    Q_OBJECT

public:
    tz30Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
};

#endif // TZ30WIDGET_H
