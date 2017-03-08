#ifndef TZ90WIDGET_H
#define TZ90WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


namespace Ui {
class tz90widget;
}

class tz90widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz90widget(QWidget *parent = 0);
    ~tz90widget();
    //void paintEvent(QPaintEvent *event);

private:
    Ui::tz90widget *ui;
};

#endif // TZ90WIDGET_H

