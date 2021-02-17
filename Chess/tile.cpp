#include "tile.h"
#include <QBrush>

Tile::Tile()
{
    setRect(0, 0, 64, 64);
    //    setBrush(QBrush(Qt::red));
}

void Tile::selectTile()
{
    setBrush(QBrush(Qt::red));
}
