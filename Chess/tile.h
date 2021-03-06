#ifndef TILE_H
#define TILE_H

#include <QGraphicsRectItem>
<<<<<<< HEAD
#include <QBrush>
=======
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d

class Tile: public QGraphicsRectItem
{
public:
<<<<<<< HEAD
    Tile(QBrush brush);
    void select(); // change tile's color
    void unselect(); // unselect tile
    bool isSelected();

    QBrush *brush;

private:
    bool selected = false;
=======
    Tile();
    void selectTile(); // change tile's color
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d
};

#endif // TILE_H
