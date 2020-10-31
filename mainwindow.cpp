#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new DataTableModel(this);
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_add_row_btn_clicked()
{
    model->insertRows(model->rowCount(), 1);
}

void MainWindow::on_delete_row_btn_clicked()
{
    QModelIndexList indexes =  ui->tableView->selectionModel()->selectedRows();
    int countRow = indexes.count();

    for( int i = countRow-1; i >= 0; i--)
           model->removeRow( indexes.at(i).row(), QModelIndex());
}
