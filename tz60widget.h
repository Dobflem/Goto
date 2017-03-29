#ifndef TZ60WIDGET_H
#define TZ60WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QtGui>

namespace Ui {
class tz60widget;
}

class tz60widget : public QWidget
{
    Q_OBJECT

public:
    explicit tz60widget(QWidget *parent = 0);
    ~tz60widget();
    QPushButton* getTokenButton();
    QPushButton* getStartConvoButton();
    QPushButton* getGiveHippieFoodButton();
    QPushButton* getGiveHippieJointButton();
    QToolButton* getNextButton();
    void hideSpeechBubble();
    void showSpeechBubble();
    void hideNextArrow();
    void showNextArrow();
    void showFoodOptions();
    void showJointOptions();
    void hideFoodOptions();
    void hideJointOptions();
    void hideNoFoodWarning();
    void showNoFoodWarning();
    void hideNoJointWarning();
    void showNoJointWarning();
    void setSpeechBubbleText(QString text);

public slots:
    void swapHippieLabels();

private:
    Ui::tz60widget *ui;
};

#endif // TZ60WIDGET_H

