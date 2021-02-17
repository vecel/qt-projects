#ifndef TILE_H
#define TILE_H

#include <QGraphicsRectItem>

class Tile: public QGraphicsRectItem
{
public:
    Tile();
    void select(); // change tile's color
    void unselect(); // unselect tile

private:
    bool selected = false;

};

#endif // TILE_H
