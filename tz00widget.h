#ifndef TZ00WIDGET_H
#define TZ00WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


namespace Ui {
class tz00widget;
}

class tz00widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz00widget(QWidget *parent = 0);
    ~tz00widget();
    //void paintEvent(QPaintEvent *event);

private:
    Ui::tz00widget *ui;
};

#endif // TZ00WIDGET_H

