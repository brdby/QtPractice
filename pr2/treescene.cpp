#include "treescene.h"

void TreeScene::drawTree(Node &rootNode)
{
    treeDrawer->setNodeCoords(rootNode);
    drawAllNodes(rootNode);
}

void TreeScene::drawAllNodes(const Node &node)
{
    drawNode(node);
    for (auto &childNode : node.childList) {
        drawAllNodes(childNode);
        drawLine(node, childNode);
    }
}

void TreeScene::drawNode(const Node &node)
{
    addRect(node.getX()*scale, node.getY()*scale, nodeWidth, nodeHeight, QPen(Qt::black));
    QGraphicsTextItem *text = addText(node.getName());
    text->setPos(node.getX()*scale, node.getY()*scale);
}

void TreeScene::drawLine(const Node &parentNode, const Node &childNode)
{
    addLine(parentNode.getX()*scale+nodeWidth/2, parentNode.getY()*scale+nodeHeight,
            childNode.getX()*scale+nodeWidth/2, childNode.getY()*scale);
}
