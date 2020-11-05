#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xmlparcer.h"
#include <QFileDialog>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new TreeScene(100, 50, 150);
    parcer = new XMLParcer();
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("All Files (*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        auto nodes = parcer->getNodes(file);
        scene->clear();
        scene->drawTree(*nodes);
    }
}
