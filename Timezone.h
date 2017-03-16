#include <map>
#include <string>
#include <vector>
#include "item.h"

#ifndef TIMEZONE_H_
#define TIMEZONE_H_

#include <QString>
#include <QWidget>
#include "backpack.h"
#include "infomessage.h"

using namespace std;
using std::vector;

class Timezone {

private:
    QString description;
    QString imagePath;
    QString mapPath;
    QString musicPath;

    map<string, Timezone*> exits;
    vector <Item> itemsInTimezone;
    Backpack *backpack;
    InfoMessage* infoMessage;

public:
    Timezone(QString description, QString path, QString mapPath, QString musicPath);

    Timezone* getNorthTimezone();
    Timezone* getSouthTimezone();
    Timezone* getEastTimezone();
    Timezone* getWestTimezone();

    void leave();
    void addItem(Item *inItem);
    void removeItemFromTimezone(int location);
    void setExits(Timezone *north, Timezone *east, Timezone *south, Timezone *west);
    bool isItemInTimezone(int itemId);
    int numberOfItems();


    // GETTERS
    QString getTZImage();
    QString getImagePath();
    QString getMapPath();
    QString getMusicPath();
    QString getDescription();
    InfoMessage* getInfoMessage();

    // SETTERS
    void setBackpack(Backpack *b);

    // VIRTUAL METHODS
    virtual QString getInfoText() { return NULL; }
    virtual void enter(Backpack *b) { this->setBackpack(b); }
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
