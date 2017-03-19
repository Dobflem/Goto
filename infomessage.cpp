#include "infomessage.h"

InfoMessage::InfoMessage(QWidget *parent) {}

QString InfoMessage::getMessage() {
    return this->message;
}

void InfoMessage::setMessage(QString msg) {
    cout << "setting infoMessage to " << msg.toStdString() << " .END" << endl;

    this->message = msg;
    emit valueChanged(this->message);
}

