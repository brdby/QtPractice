#ifndef TREESCENE_H
#define TREESCENE_H

#include <QGraphicsScene>
#include "node.h"
#include "treedrawer.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>

class TreeScene : public QGraphicsScene
{
public:
    TreeScene(int w, int h, int s) : nodeWidth(w), nodeHeight(h), scale(s), treeDrawer(new TreeDrawer()) {};
    void drawTree(Node &rootNode);
private:
    void drawAllNodes(const Node &node);
    void drawNode(const Node &node);
    void drawLine(const Node &parentNode, const Node &childNode);
    void setNodeCoords(const Node &rootNode);

    int nodeWidth;
    int nodeHeight;
    int scale;
    TreeDrawer *treeDrawer;
};

#endif // TREESCENE_H
