#include "backpack.h"
#include <QDebug>
#include <vector>
#include "item.h"

Backpack::Backpack() {
    this->contents = new InfoMessage();
    this->contents->setMessage("");
}

Backpack::~Backpack() {
}

void Backpack::addItem(Item *i) {
    this->items.add(i);
    setContentsString();
    this->contents->setMessage(this->contentsString);
}

InfoMessage *Backpack::getContents() {
    return contents;
}

void Backpack::setContentsString() {
    this->contentsString = "";
    for(items.start(); items.currentItem != NULL; ++items) {
        this->contentsString.append(items.currentItem->getDescription());
        this->contentsString.append(", ");
    }
}

Item *Backpack::getItem(int id) {
    for(items.start(); items.currentItem != NULL; items.next()) {
        if (items.currentItem->getID() == id) {
            return items.currentItem;
        }
    } return NULL;
}

void Backpack::removeItem(int id) {
    for(items.start(); items.currentItem != NULL; items.next()) {
        if (items.currentItem->getID() == id) {
            this->items.remove(items.getCurrentIndex());
        }
    }
    setContentsString();
    this->contents->setMessage(this->contentsString);
}

bool Backpack::hasItem(int id) {
    for(items.start(); items.currentItem != NULL; items.next()) {
        if (items.currentItem->getID() == id) {
            return true;
        }
    } return false;
}

