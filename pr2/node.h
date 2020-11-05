#ifndef NODE_H
#define NODE_H

#include <QVector>

class Node
{
private:
    int x = 0;
    int y = 0;
    int mod = 0;
    QString name;
public:
    Node(const QString &n = "") : name(n) {};

    void addChild(const Node &child);

    int getX() const;
    int getY() const;
    void setX(int value);
    void setY(int value);
    int getMod() const;
    void setMod(int value);
    QString getName() const;

    QVector<Node> childList;
};

#endif // NODE_H
