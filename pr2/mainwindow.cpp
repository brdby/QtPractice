#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new TreeScene(50, 50, 100);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Node rootNode(0, 0);
    rootNode.addChild(Node(0, 1));
    rootNode.addChild(Node(1, 1));
    rootNode.addChild(Node(2, 1));
    rootNode.addChild(Node(3, 1));
    scene->drawTree(rootNode);
}
