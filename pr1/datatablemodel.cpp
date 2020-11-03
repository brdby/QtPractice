#include "datatablemodel.h"

DataTableModel::DataTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant DataTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QStringLiteral("Name");
        case 1:
            return QStringLiteral("Type");
        default:
            return QVariant();
        }
    } else return QStringLiteral("Animal %1").arg(section);
}

int DataTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return dataList.count();
}

int DataTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 2;
}

QVariant DataTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= dataList.size())
        return QVariant();

    if (role == Qt::DisplayRole){
        auto &animal = dataList[index.row()];

        switch (index.column()) {
        case 0:
            return animal.name;
        case 1:
            return animal.type;
        }
    }
    return QVariant();
}

bool DataTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);

    for (int i = 0; i < count; ++i) {
            dataList.insert(row, Animal());
    }

    endInsertRows();
    return true;
}

bool DataTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    return false;
}

Qt::ItemFlags DataTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool DataTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        auto &animal = dataList[index.row()];

        switch (index.column()) {
        case 0:
            animal.name = value.toString();
            break;
        case 1:
            animal.type = value.toString();
            break;
        }

        emit dataChanged(index, index, {role});
    }
    return false;
}

bool DataTableModel::saveData(QFile &file, AnimalSerializer *serializer) const
{
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }
    QTextStream out(&file);

    for (auto &animal : dataList) {
        out << serializer->toString(animal);
    }
    return true;
}

bool DataTableModel::loadData(QFile &file, AnimalSerializer *serializer)
{
    emit layoutAboutToBeChanged();
    if (!file.open(QIODevice::ReadOnly))
            return false;

    dataList.clear();
    QTextStream in(&file);

    for (int i = 0; !in.atEnd(); ++i) {
        QString line = in.readLine();
        dataList.insert(i, serializer->fromString(line));
    }
    emit layoutChanged();
    return true;
}

bool DataTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    for (int i = 0; i < count; ++i) {
            dataList.removeAt(row);
    }
    endRemoveRows();
    return true;
}

bool DataTableModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    return false;
}


