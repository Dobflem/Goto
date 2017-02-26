#include "Timezone.h"

#ifndef TZ30_H
#define TZ30_H


class TZ30 : public Timezone
{
public:
    TZ30(QString description, QString image):Timezone(description, image)
    {
        // Don't need to do anything
    }

    bool canEnterRoom();
};

#endif // TZ30_H
