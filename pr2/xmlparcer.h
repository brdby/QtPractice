#ifndef XMLPARCER_H
#define XMLPARCER_H

#include "parcer.h"
#include <QXmlStreamReader>

class XMLParcer : public Parcer
{
public:
    Node* getNodes(QFile &file);
private:
    void parceNodes(Node *root, int depth, QXmlStreamReader &xml);
};

#endif // XMLPARCER_H
