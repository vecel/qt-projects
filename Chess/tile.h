#ifndef TILE_H
#define TILE_H

#include <QGraphicsRectItem>

class Tile: public QGraphicsRectItem
{
public:
    Tile();
    void selectTile(); // change tile's color
};

#endif // TILE_H
