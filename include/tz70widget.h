#ifndef TZ70WIDGET_H
#define TZ70WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


class tz70Widget : public QWidget
{
    Q_OBJECT

public:
    tz70Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
};

#endif // TZ70WIDGET_H
