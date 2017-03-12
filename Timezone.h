#include <map>
#include <string>
#include <vector>
#include "item.h"

#ifndef TIMEZONE_H_
#define TIMEZONE_H_

#include <QString>
#include <QWidget>
#include "backpack.h"

using namespace std;
using std::vector;

class Timezone {

private:
    QString description;
    QString imagePath;
    QString mapPath;
    QString exitString();

    map<string, Timezone*> exits;
    vector <Item> itemsInTimezone;
    Backpack *backpack;

public:
    Timezone(QString description, QString path, QString mapPath);

    Timezone* getNorthTimezone();
    Timezone* getSouthTimezone();
    Timezone* getEastTimezone();
    Timezone* getWestTimezone();


    void leave();
    void addItem(Item *inItem);
    void removeItemFromTimezone(int location);
    void setExits(Timezone *north, Timezone *east, Timezone *south, Timezone *west);
    void enter(Backpack *b);

    int numberOfItems();
    int isItemInTimezone(string inString);

    QString displayItem();
    QString shortDescription();
    QString longDescription();

    // GETTERS
    QString getTZImage();
    QString getImagePath();
    QString getMapPath();

    // VIRTUAL METHODS
    virtual ~Timezone() {}
    virtual bool canEnterRoom(Backpack *b = NULL) { return true; }
    virtual QWidget* getTimezoneWidget() {
       //currently returning empty widget as default.
       //This needs to be changed

        cout << "In default get timezone widget" << endl;
        QWidget *def = new QWidget();
        return def;
    }

    //virtual QWidget* getTimezoneWidget() = 0;
};

#endif
