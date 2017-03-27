#include "tzpresent.h"

bool TZPresent::canEnterRoom(Backpack *b) {
    return (b->hasItem(10));
}

QWidget* TZPresent::getTimezoneWidget() {
    return widget;
}

void TZPresent::enter(Backpack *b) {
    this->setBackpack(b);
    this->displayInfo();
}

void TZPresent::leave() {
    // Timezone::leave();
}

void TZPresent::displayInfo() {
    Timezone::getInfoMessage()->setMessage("Well done! You made it to the present day. The era of Brexit and Trump!! What were you thinking? You were better off in the past. GAME OVER");
}

