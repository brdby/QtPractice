#ifndef ANIMALCSVSERIALIZER_H
#define ANIMALCSVSERIALIZER_H

#include "animalserializer.h"

class AnimalCsvSerializer : public AnimalSerializer
{
public:
    virtual QString toString(const Animal &animal) override;
    virtual Animal fromString(const QString &csvString) override;
};

#endif // ANIMALCSVSERIALIZER_H
