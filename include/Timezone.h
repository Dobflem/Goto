#include <map>
#include <string>
#include <vector>
#include "item.h"

#ifndef TIMEZONE_H_
#define TIMEZONE_H_

#include <QString>
#include <QWidget>

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


    // GETTERS
    QString getTZImage();
    QString getImagePath();

    // VIRTUAL METHODS
    virtual ~Timezone() {}
    virtual bool canEnterRoom() { return true; }
    virtual QWidget* getTimezoneWidget() {
       //currently returning empty widget as default.
       //This needs to be changed

        QWidget *def = new QWidget();
        return def;
    }

    //virtual QWidget* getTimezoneWidget() = 0;
};

#endif
