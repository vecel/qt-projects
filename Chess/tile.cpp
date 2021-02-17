#include "tile.h"
#include <QBrush>

#include <QDebug>

Tile::Tile()
{
    setRect(0, 0, 64, 64);
    //    setBrush(QBrush(Qt::red));
}

void Tile::select()
{
    setBrush(QBrush(Qt::red));
    selected = true;
}

void Tile::unselect()
{
    setBrush(QBrush(Qt::white));
    selected = false;
}
