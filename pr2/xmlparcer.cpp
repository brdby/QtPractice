#include "xmlparcer.h"

Node* XMLParcer::getNodes(QFile &file)
{
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return new Node();

    QXmlStreamReader xml(&file);
    while (!xml.atEnd()) {
        xml.readNext();
        if (xml.isStartElement()) {
            Node *root = new Node(xml.attributes().value("name").toString());
            root->setY(0);
            xml.readNext();
            parceNodes(root, 1, xml);
            return root;
        }
    }
    return new Node;
}

void XMLParcer::parceNodes(Node *root, int depth, QXmlStreamReader &xml) {
    bool inELem = false;
    int count = -1;
    while (!xml.atEnd()) {
        if (xml.isEndElement()) {
            if (inELem) inELem=false;
            else return;
        }
        else if (xml.isStartElement()) {
            if (inELem){
                inELem = false;
                parceNodes(&root->childList[count], depth+1, xml);
            }
            else {
                Node *childNode = new Node(xml.attributes().value("name").toString());
                childNode->setY(depth);
                root->childList.append(*childNode);
                inELem=true;
                count++;
            }
        }
        xml.readNext();
    }
}
