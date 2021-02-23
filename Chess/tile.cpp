#include "tile.h"
#include <QBrush>
#include "board.h"

#include <QDebug>

Tile::Tile()
{
    setRect(0, 0, 64, 64);
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

bool Tile::isSelected()
{
    return selected;
}
