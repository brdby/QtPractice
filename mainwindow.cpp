#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new DataTableModel(this);
    defaultSerializer = new AnimalCsvSerializer();
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete defaultSerializer;
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

void MainWindow::on_save_btn_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"), "", tr("All Files (*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!model->saveData(file, defaultSerializer))
            QMessageBox::information(this, tr("Unable to save data"), file.errorString());
    }
}

void MainWindow::on_load_btn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("All Files (*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!model->loadData(file, defaultSerializer))
            QMessageBox::information(this, tr("Unable to load data"), file.errorString());
    }
}
