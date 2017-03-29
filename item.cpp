#include "item.h"

Item::Item(const int id, const QString& desc) {
    this->ID = id;
    this->description = desc;
}

int Item::getID() {
    return this->ID;
}

QString Item::getDescription() {
    return this->description;
}
