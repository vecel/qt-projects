#include "tile.h"
#include <QBrush>
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
}
