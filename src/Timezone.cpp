#include "include/Timezone.h"
#include "include/Command.h"


Timezone::Timezone(QString description, QString path) {
	this->description = description;
    this->imagePath = path;
}

QString Timezone::getTZImage() {
    return this->imagePath;
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

/*
string Timezone::getImagePath() {
    return imagePath;
}

string Timezone::shortDescription() {
	return description;
}

string Timezone::longDescription() {
    return "timezone = " + description + ".\n" + displayItem() + exitString();
}

string Timezone::exitString() {
    string returnString = "\nAvailable exits =";
	for (map<string, Timezone*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}

Timezone* Timezone::nextTimezone(string direction) {
	map<string, Timezone*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end()) {
        return NULL;
    }// if exits.end() was returned, there's no timezone in that direction.
    return next->second; // If there is a timezone, remove the "second" (Timezone*)
                // part of the "pair" (<string, Timezone*>) and return it.
}

void Timezone::addItem(Item *inItem) {
    itemsInTimezone.push_back(*inItem);
}

string Timezone::displayItem() {
    string tempString = "items in timezone = ";
    int sizeItems = (itemsInTimezone.size());
    if (itemsInTimezone.size() < 1) {
        tempString = "no items in timezone";
    } else if (itemsInTimezone.size() > 0) {
       int x = (0);
       for (int n = sizeItems; n > 0; n--) {
        tempString = tempString + itemsInTimezone[x].getShortDescription() + "  " ;
        x++;
       }
    }
    return tempString;
}

int Timezone::numberOfItems() {
    return itemsInTimezone.size();
}

int Timezone::isItemInTimezone(string inString) {
    int sizeItems = (itemsInTimezone.size());
    if (itemsInTimezone.size() < 1) {
        return false;
    } else if (itemsInTimezone.size() > 0) {
       int x = (0);
       for (int n = sizeItems; n > 0; n--) {
           // compare inString with short description
           int tempFlag = inString.compare( itemsInTimezone[x].getShortDescription());
           if (tempFlag == 0) {
               itemsInTimezone.erase(itemsInTimezone.begin()+x);
               return x;
           }
           x++;
        }
    }
    return -1;
}
*/
