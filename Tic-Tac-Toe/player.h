#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>

class QPainter;
class QStyleOptionGraphicsItem;


class Player : public QGraphicsRectItem
{
public:

    enum CurrentPlayer
    {
        PlayerOne,
        PlayerTwo
    };

    Player(QGraphicsItem *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


    CurrentPlayer getCurrentPlayer() const;
    void setCurrentPlayer(CurrentPlayer newCurrentPlayer);


private:
    CurrentPlayer currentPlayer;
};

#endif // PLAYER_H
