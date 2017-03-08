#ifndef TZ20WIDGET_H
#define TZ20WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


namespace Ui {
class tz20widget;
}

class tz20widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz20widget(QWidget *parent = 0);
    ~tz20widget();
    //void paintEvent(QPaintEvent *event);

private:
    Ui::tz20widget *ui;
};

#endif // TZ20WIDGET_H

