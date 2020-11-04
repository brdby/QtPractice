#include "treescene.h"

void TreeScene::drawTree(const Node &rootNode)
{
    treeDrawer->setNodeCoords(rootNode);
    drawAllNodes(rootNode);
}

void TreeScene::drawAllNodes(const Node &node)
{
    drawNode(node);
    for (auto &childNode : node.getChildList()) {
        drawAllNodes(childNode);
        drawLine(node, childNode);
    }
}

void TreeScene::drawNode(const Node &node)
{
    addRect(node.getX()*scale, node.getY()*scale, nodeWidth, nodeHeight, QPen(Qt::black), QBrush(Qt::black));
}

void TreeScene::drawLine(const Node &parentNode, const Node &childNode)
{
    addLine(parentNode.getX()*scale+nodeWidth/2, parentNode.getY()*scale+nodeHeight,
            childNode.getX()*scale+nodeWidth/2, childNode.getY()*scale);
}
