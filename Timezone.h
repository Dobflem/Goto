#include <map>
#include <string>
#include <vector>
#include "item.h"

#ifndef TIMEZONE_H_
#define TIMEZONE_H_

#include <QString>
#include <QDebug>
#include <QWidget>
#include "backpack.h"
#include "infomessage.h"

using namespace std;
using std::vector;

class Timezone {

protected:
    vector<Item> itemsInTimezone;

private:
    QString description;
    QString imagePath;
    QString mapPath;
    QString musicPath;

    map<string, Timezone*> exits;
    Backpack *backpack;
    InfoMessage* infoMessage;

public:
    Timezone(QString description, QString path, QString mapPath, QString musicPath);

    Timezone* getNorthTimezone();
    Timezone* getSouthTimezone();
    Timezone* getEastTimezone();
    Timezone* getWestTimezone();

    void addItem(Item *inItem);
    void setExits(Timezone *north, Timezone *east, Timezone *south, Timezone *west);
    bool isItemInTimezone(int itemId);
    int getLocationOfItemInTimezone(int itemId);
    int numberOfItems();
    void leaveTimezone();


    // GETTERS
    QString getTZImage() const;
    QString getImagePath() const;
    QString getMapPath() const;
    QString getMusicPath() const;
    QString getDescription() const;
    InfoMessage* getInfoMessage() const;
    Backpack* getBackpack() const;
    vector<Item> getItemsInTimezone() const;


    // SETTERS
    void setBackpack(Backpack *b);


    // VIRTUAL METHODS
    virtual ~Timezone() {
        delete this;
    }

    virtual bool canEnterRoom(Backpack *b) {
        if(b != NULL) {
            return true;
        } else {
            return false;
        }
    }

    virtual void leave() {
        this->leaveTimezone();
    }

    //PURE VIRTUAL METHODS
    virtual QWidget* getTimezoneWidget() = 0;
    virtual void enter(Backpack *b) = 0;
};

#endif
