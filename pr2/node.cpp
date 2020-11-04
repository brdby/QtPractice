#include "node.h"

int Node::getX() const
{
    return x;
}

int Node::getY() const
{
    return y;
}

QList<Node> Node::getChildList() const
{
    return childList;
}

void Node::setX(int value)
{
    x = value;
}

void Node::setY(int value)
{
    y = value;
}

void Node::addChild(const Node &child)
{
    childList.append(child);
}
