#ifndef NODE_H
#define NODE_H

#include <QList>

class Node
{
    int x;
    int y;
    int mod;
    QList<Node> childList;
public:
    Node(int x, int y) : x(x), y(y) {};

    void addChild(const Node &child);
    QList<Node> getChildList() const;

    int getX() const;
    int getY() const;
    void setX(int value);
    void setY(int value);
    int getMod() const;
    void setMod(int value);
};

#endif // NODE_H
