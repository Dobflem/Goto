#include "Timezone.h"

#ifndef TZPRESENT_H
#define TZPRESENT_H


class TZPresent : public Timezone
{
public:
    TZPresent(QString description, QString image):Timezone(description, image)
    {
        // Don't need to do anything
    }

    bool canEnterRoom();
};

#endif // TZPRESENT_H
