#ifndef TZ70WIDGET_H
#define TZ70WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>


namespace Ui {
class tz70widget;
}

class tz70widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz70widget(QWidget *parent = 0);
    ~tz70widget();
   // void paintEvent(QPaintEvent *event);

private:
    Ui::tz70widget *ui;
};

#endif // TZ70WIDGET_H

