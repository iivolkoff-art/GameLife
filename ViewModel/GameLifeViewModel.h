#ifndef GAMELIFEVIEWMODEL_H
#define GAMELIFEVIEWMODEL_H

#include <QAbstractTableModel>
#include <string>


#include "../Model/MainClass/GameLife.h"

class GameLifeViewModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(int rows READ rowCount CONSTANT)
    Q_PROPERTY(int cols READ columnCount CONSTANT)

private:
    GameLife* gameLife;

public:
    enum LifeRoles { IsAliveRole = Qt::UserRole + 1 };
    explicit GameLifeViewModel(GameLife* gl, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
};

#endif // GAMELIFEVIEWMODEL_H
