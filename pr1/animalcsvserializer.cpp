#include "animalcsvserializer.h"

QString AnimalCsvSerializer::toString(const Animal &animal) {
    return QString("%1,%2\n").arg(escapeCommas(animal.name)).arg(escapeCommas(animal.type));
}

Animal AnimalCsvSerializer::fromString(const QString &csvString) {
    QRegularExpression re("(?:^\"|,\")(\"\"|[\\w\\W]*?)(?=\",|\"$)|(?:^(?!\")|,(?!\"))([^,]*?)(?=$|,)|(\\r\\n|\\n)");
    auto iter = re.globalMatch(csvString);
    QStringList words;
    while (iter.hasNext()) {
        auto match = iter.next();
        words << match.captured(match.lastCapturedIndex());
    }
    if (words.size() == 2) return {words[0], words[1]};
    else return {};
}

QString AnimalCsvSerializer::escapeCommas(const QString &string)
{
    return (string.contains(',')|string.contains('"')) ? QString("\"%1\"").arg(string) : string;
}
