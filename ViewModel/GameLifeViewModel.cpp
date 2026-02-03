#include "GameLifeViewModel.h"
GameLifeViewModel::GameLifeViewModel(GameLife* gl, QObject *parent)
    : QAbstractTableModel(parent)
    , gameLife(gl)
{
    connect(gameLife, &GameLife::mapUpdated, this, [this]() {
        int rows = rowCount();
        int cols = columnCount();
        emit dataChanged(index(0, 0), index(rows - 1, cols - 1));
    }, Qt::QueuedConnection);
}

int GameLifeViewModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid() || !gameLife) return 0;

    return gameLife->GetGrid().getRows();
}

int GameLifeViewModel::columnCount(const QModelIndex &parent) const {
    if (parent.isValid() || !gameLife) return 0;
    return gameLife->GetGrid().getCols();
}

QHash<int, QByteArray> GameLifeViewModel::roleNames() const {
    return { {IsAliveRole, "isAlive"} };
}

QVariant GameLifeViewModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != IsAliveRole || !gameLife) return QVariant();
    const auto& cells = gameLife->GetGrid().getCells();

    return cells[index.row()][index.column()];
}
