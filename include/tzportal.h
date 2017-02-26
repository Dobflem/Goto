#include "Timezone.h"

#ifndef TZPORTAL_H
#define TZPORTAL_H

class TZPortal: public Timezone
{
public:
    TZPortal(QString description, QString image):Timezone(description, image)
    {
        // Don't need to do anything
    }
};

#endif // TZPORTAL_H
