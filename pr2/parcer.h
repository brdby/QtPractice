#ifndef PARCER_H
#define PARCER_H

#include <QList>
#include <QFile>
#include <node.h>

class Parcer
{
public:
    virtual Node* getNodes(QFile &file) = 0;
    virtual ~Parcer() = default;
};

#endif // PARCER_H
