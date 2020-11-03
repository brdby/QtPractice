#ifndef DATATABLEVIEW_H
#define DATATABLEVIEW_H

#include "animal.h"
#include "animalserializer.h"

#include <QAbstractTableModel>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class DataTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit DataTableModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // Edit data
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    // Save data
    bool saveData(QFile &file, AnimalSerializer *serializer) const;
    bool loadData(QFile &file, AnimalSerializer *serializer);

private slots:


private:
    QList<Animal> dataList;
};

#endif // DATATABLEVIEW_H
