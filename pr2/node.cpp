#include "node.h"

int Node::getX() const
{
    return x;
}

int Node::getY() const
{
    return y;
}

void Node::setX(int value)
{
    x = value;
}

void Node::setY(int value)
{
    y = value;
}

int Node::getMod() const
{
    return mod;
}

void Node::setMod(int value)
{
    mod = value;
}

QString Node::getName() const
{
    return name;
}

void Node::addChild(const Node &child)
{
    childList.append(child);
}
