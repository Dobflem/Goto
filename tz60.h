#include "Timezone.h"

#ifndef TZ60_H
#define TZ60_H


class TZ60 : public Timezone
{
public:
    TZ60(QString description, QString image):Timezone(description, image)
    {
        // Don't need to do anything
    }
};

#endif // TZ60_H
