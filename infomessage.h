#ifndef INFOMESSAGE_H
#define INFOMESSAGE_H

#include <QString>
#include <QObject>
#include <iostream>

using namespace std;


class InfoMessage : public QObject
{
    Q_OBJECT

private:
    QString message;

public:
    explicit InfoMessage();

    QString getMessage();
    void setMessage(const QString& message);

signals:
    void valueChanged(QString);
};


#endif // INFOMESSAGE_H
