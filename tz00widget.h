#ifndef TZ00WIDGET_H
#define TZ00WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QtGui>
#include <QDebug>


namespace Ui {
class tz00widget;
}

class tz00widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz00widget(QWidget *parent = 0);
    ~tz00widget();

    QPushButton* getTokenButton();
    QPushButton* getSubmitButton();
    bool getTitanicCheckBox();
    bool getNelsonCheckBox();
    bool getMjCheckBox();
    bool getIpodCheckBox();
    bool getBigBrotherCheckBox();
    bool getYoutubeCheckBox();
    QLabel* getWarningLabel();
    QFrame* getGameFrame();

private:
    Ui::tz00widget *ui;
};

#endif // TZ00WIDGET_H

