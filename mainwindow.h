#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "datatablemodel.h"
#include "animalcsvserializer.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_row_btn_clicked();

    void on_delete_row_btn_clicked();

    void on_save_btn_clicked();

    void on_load_btn_clicked();

private:
    Ui::MainWindow *ui;
    DataTableModel *model;
};
#endif // MAINWINDOW_H
