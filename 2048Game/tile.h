#ifndef TILE_H
#define TILE_H

#include <QGraphicsLayoutItem>

class Tile : public QGraphicsLayoutItem
{
public:
    Tile(int val = 2);
    ~Tile();
    int getValue();

private:
    int value;
};

#endif // TILE_H
