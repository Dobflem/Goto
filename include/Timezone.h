#include <map>
#include <string>
#include <vector>
#include "item.h"

#ifndef TIMEZONE_H_
#define TIMEZONE_H_

#include <QString>

using namespace std;
using std::vector;

class Timezone {

private:
    QString description;
    QString imagePath;
    QString exitString();

    map<string, Timezone*> exits;
    vector <Item> itemsInTimezone;

public:
    Timezone(QString description, QString path);

    Timezone* getNorthTimezone();
    Timezone* getSouthTimezone();
    Timezone* getEastTimezone();
    Timezone* getWestTimezone();

    void addItem(Item *inItem);
    void removeItemFromTimezone(int location);
    void setExits(Timezone *north, Timezone *east, Timezone *south, Timezone *west);

    int numberOfItems();
    int isItemInTimezone(string inString);

    QString displayItem();
    QString shortDescription();
    QString longDescription();
    QString getImagePath();

    // GETTERS
    QString getTZImage();

    // VIRTUAL METHODS
    virtual ~Timezone() = default;
    virtual bool canEnterRoom() {
      return true;
    }
};

#endif
