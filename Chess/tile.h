#ifndef TILE_H
#define TILE_H

#include <QGraphicsRectItem>
#include <QBrush>

class Tile: public QGraphicsRectItem
{
public:
    Tile(QBrush brush);
    void select(); // change tile's color
    void unselect(); // unselect tile
    bool isSelected();

    QBrush *brush;

private:
    bool selected = false;
};

#endif // TILE_H
