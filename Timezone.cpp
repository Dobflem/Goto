#include "Timezone.h"

Timezone::Timezone(QString description, QString path, QString mapPath, QString musicPath) {
	this->description = description;
    this->imagePath = path;
    this->mapPath = mapPath;
    this->musicPath = musicPath;
    this->infoMessage = new InfoMessage();
}

QString Timezone::getTZImage() const {
    return this->imagePath;
}

QString Timezone::getMapPath() const {
    return this->mapPath;
}

QString Timezone::getMusicPath() const {
    return this->musicPath;
}

QString Timezone::getDescription() const {
    return description;
}

InfoMessage* Timezone::getInfoMessage() const {
    return infoMessage;
}

Backpack* Timezone::getBackpack() const {
    return backpack;
}

vector<Item> Timezone::getItemsInTimezone() const {
    return itemsInTimezone;
}

void Timezone::setExits(Timezone *north, Timezone *east, Timezone *south, Timezone *west) {
	if (north != NULL)
        this->exits["north"] = north;
	if (east != NULL)
        this->exits["east"] = east;
	if (south != NULL)
        this->exits["south"] = south;
	if (west != NULL)
        this->exits["west"] = west;
}

Timezone* Timezone::getNorthTimezone() {
    return this->exits["north"];
}

Timezone* Timezone::getSouthTimezone() {
    return this->exits["south"];
}

Timezone* Timezone::getEastTimezone() {
    return this->exits["east"];
}

Timezone* Timezone::getWestTimezone() {
    return this->exits["west"];
}

void Timezone::setBackpack(Backpack *b) {
    this->backpack = b;
}

void Timezone::leaveTimezone() {
    this->backpack = NULL;
}

void Timezone::addItem(Item *inItem) {
    itemsInTimezone.push_back(*inItem);
}

int Timezone::numberOfItems() {
    return itemsInTimezone.size();
}

bool Timezone::isItemInTimezone(int itemId) {
    if (itemsInTimezone.size() < 1) {
        return false;
    } else {
        for(vector<Item>::size_type i = 0; i != itemsInTimezone.size(); i++) {
            if(itemId == itemsInTimezone[i].getID()) {
                return true;
            }
        }
    }
    return false;
}

int Timezone::getLocationOfItemInTimezone(int itemId) {
    if (itemsInTimezone.size() < 1) {
        return false;
    } else {
        for(vector<Item>::size_type i = 0; i != itemsInTimezone.size(); i++) {
            if(itemId == itemsInTimezone[i].getID()) {
                return i;
            }
        }
    }
    return false;
}
