#include "positionrect.h"
#include <QPen>
#include <QBrush>

PositionRect::PositionRect(QGraphicsItem* parent) :
    QGraphicsRectItem{parent},
    gridPos(),
    pos(0)
{
    setPen(QPen(QBrush(QColor(Qt::black )) , 3));

}

int PositionRect::getPos() const
{
    return pos;
}

void PositionRect::setPos(int newPos)
{
    pos = newPos;
}


