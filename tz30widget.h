#ifndef TZ30WIDGET_H
#define TZ30WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


namespace Ui {
class tz30widget;
}

class tz30widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz30widget(QWidget *parent = 0);
    ~tz30widget();
    //void paintEvent(QPaintEvent *event);

private:
    Ui::tz30widget *ui;
};

#endif // TZ30WIDGET_H

