#include "Timezone.h"

#ifndef TZ90_H
#define TZ90_H


class TZ90 : public Timezone
{
public:
    TZ90(QString description, QString image):Timezone(description, image)
    {
        // Don't need to do anything
    }
};

#endif // TZ90_H
