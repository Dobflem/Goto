#include "backpack.h"
#include <QDebug>
#include <vector>
#include "item.h"

Backpack::Backpack() {
    this->items = new List<Item>();
    this->contents = new InfoMessage();
    this->contents->setMessage("");
}

Backpack::~Backpack() {
    delete this->items;
}

void Backpack::addItem(Item *i) {

    qDebug() << "Adding item to backpack" << i->getDescription();

    items->add(i);
    qDebug() << "item added";

    // items.push_back(i);
    setContentsString();
    qDebug() << "Set contents string";
    this->contents->setMessage(this->contentsString);
    qDebug() << "set contents message";
}

InfoMessage* Backpack::getContents() {
    return contents;
}

void Backpack::setContentsString() {
    this->contentsString = "";
    for(items->start(); items->currentItem != NULL; items->next()) {
        this->contentsString.append(items->currentItem->getDescription());
        this->contentsString.append(", ");
    }
}

Item *Backpack::getItem(int id) {
    for(items->start(); items->currentItem != NULL; items->next()) {
        if (items->currentItem->getID() == id) {
            return items->currentItem;
        }
    } return NULL;
}

bool Backpack::hasItem(int id) {
    for(items->start(); items->currentItem != NULL; items->next()) {
        if (items->currentItem->getID() == id) {
            qDebug() << items->currentItem->getDescription() << endl;
            return true;
        }
    } return false;
}
