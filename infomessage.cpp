#include "infomessage.h"

InfoMessage::InfoMessage(QWidget *parent) {

}

QString InfoMessage::getMessage() {
    return this->message;
}

void InfoMessage::setMessage(QString msg) {
    cout << "in set message in infoMessage" << endl;
    this->message = msg;
    emit valueChanged();
}

