#ifndef POSITIONRECT_H
#define POSITIONRECT_H

#include <QGraphicsRectItem>

class QPen;
class QBrush;

class PositionRect : public QGraphicsRectItem
{
public:
    PositionRect(QGraphicsItem *parent = nullptr);


    int getPos() const;
    void setPos(int newPos);

    QList<int> gridPos;

private:


    int pos;
};

#endif // POSITIONRECT_H
