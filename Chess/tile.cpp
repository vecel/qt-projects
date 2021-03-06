#include "tile.h"
#include <QBrush>
<<<<<<< HEAD
#include "board.h"

#include <QDebug>

Tile::Tile(QBrush brush)
{
    setRect(0, 0, 64, 64);

    this->brush = new QBrush(brush);

    setBrush(*(this->brush));
}

void Tile::select()
{
    setBrush(QBrush(Qt::red));
    selected = true;
}

void Tile::unselect()
{
    setBrush(*brush);
    selected = false;
}

bool Tile::isSelected()
{
    return selected;
=======

Tile::Tile()
{
    setRect(0, 0, 64, 64);
    //    setBrush(QBrush(Qt::red));
}

void Tile::selectTile()
{
    setBrush(QBrush(Qt::red));
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d
}
