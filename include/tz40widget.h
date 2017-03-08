#ifndef TZ40WIDGET_H
#define TZ40WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


namespace Ui {
class tz40widget;
}

class tz40widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz40widget(QWidget *parent = 0);
    ~tz40widget();
    void paintEvent(QPaintEvent *event);

private:
    Ui::tz40widget *ui;
};

#endif // TZ40WIDGET_H

