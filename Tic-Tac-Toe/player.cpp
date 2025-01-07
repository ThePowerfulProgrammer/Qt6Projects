#include "player.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsEllipseItem>

Player::Player(QGraphicsItem *parent)
    : QGraphicsRectItem(parent)
{
    setPen(QPen(QBrush(QColor(Qt::black )) , 3));
}


void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    switch (currentPlayer)
    {
        case PlayerOne :
            {
                painter->save();
                // all drawing between here
                painter->setPen(QPen(QBrush(QColor(0,225,0,255)),3   )  );
                painter->drawEllipse(rect().center(), 80,80);


                painter->restore();
            }
            break;

        case PlayerTwo :
            {
                painter->save();
                // all drawing between here

                QPointF rectTopLeft = rect().topLeft() + QPointF(20,20);
                QPointF rectTopRight = rect().topRight() + QPointF(-20,20);

                QPointF rectBottomRight = rect().bottomRight() + QPointF(-20,-20);
                QPointF rectBottomLeft =  rect().bottomLeft() + QPointF(20,-20);

                painter->setPen(QPen(QBrush(QColor(0,0,225,255)),3   )  );

                painter->drawLine(QLineF(rectTopLeft, rectBottomRight));
                painter->drawLine(QLineF(rectTopRight, rectBottomLeft));


                painter->restore();
            }
            break;

    }


    QGraphicsRectItem::paint(painter,option,widget);
}

Player::CurrentPlayer Player::getCurrentPlayer() const
{
    return currentPlayer;
}

void Player::setCurrentPlayer(CurrentPlayer newCurrentPlayer)
{
    currentPlayer = newCurrentPlayer;
}






