#ifndef TZ30WIDGET_H
#define TZ30WIDGET_H

#include <QWidget>
#include <QTime>
#include <QPainter>
#include <QColor>
#include <QPoint>
#include <QLabel>
#include <QPushButton>

#include "clickablelabel.h"
#include "backpack.h"


namespace Ui {
class tz30widget;
}

class tz30widget : public QWidget
{
Q_OBJECT
friend class TZ30;

public:
    explicit tz30widget(QWidget *parent = 0);
    ~tz30widget();
    ClickableLabel *getCapone();
    void showToken();
    bool tokenVisible();
    QPushButton *getToken();

private:
    Ui::tz30widget *ui;

public slots:
    void caponeGeometoryChanged(int x, int y);
    void toggleCapone();
};

#endif // TZ30WIDGET_H

