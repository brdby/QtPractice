#ifndef ANIMALCSVSERIALIZER_H
#define ANIMALCSVSERIALIZER_H

#include "animalserializer.h"
#include <QRegularExpression>

class AnimalCsvSerializer : public AnimalSerializer
{
public:
    virtual QString toString(const Animal &animal) override;
    virtual Animal fromString(const QString &csvString) override;

private:
    QString escapeCommas(const QString &string);
};

#endif // ANIMALCSVSERIALIZER_H
