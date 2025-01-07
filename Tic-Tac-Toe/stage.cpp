#include "stage.h"
#include "positionrect.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QGraphicsTextItem>
#include <QString>

#include "player.h"

Stage::Stage(QObject *parent)
    : QGraphicsScene{parent},
    isCurrentPlayer(true),
    currentPlayingText("Current Player: Player One O's"),
    gridCheckedPositions(),
    playedGrid(),

    isSquareZero(false),
    isSquareOne(false),
    isSquareTwo(false),
    isSquareThree(false),
    isSquareFour(false),
    isSquareFive(false),
    isSquareSix(false),
    isSquareSeven(false),
    isSquareEight(false)

{


    for (int i=0;i<3;i++)
    {
        for (int j = 0; j < 3; j++)
        {

            PositionRect *rect = new PositionRect;
            rect->setRect(QRectF(QPointF(i*200,j*200), QSize(200,200))            );
            rect->setPen(QColor(Qt::black));
            rect->setPos( i + j + (i*2)  ) ;

            rect->gridPos.append(rect->getPos());

            addItem(rect);
        }


        /*
        0 0 1 2 = 0 1 2         = 0 1 2
        1 0 1 2 = 1 2 3 + (i*2) = 3 4 5
        2 0 1 2 = 2 3 4 + (i*2) = 6 7 8

        but actually:
        0 3 6
        1 4 7
        2 5 8
        */
    }



}

void Stage::setSquareBool(int i)
{

    switch(i)
    {
    case 0:
    {
        isSquareZero = true;
        qDebug() << "Will switch on: " << i << "\n";
    }
    break;

    case 1:
    {
        isSquareOne = true;
        qDebug() << "Will switch on: " << i << "\n";
    }
    break;

    case 2:
    {
        isSquareTwo = true;
        qDebug() << "Will switch on: " << i << "\n";
    }
    break;

    case 3:
    {
        isSquareThree= true;
        qDebug() << "Will switch on: " << i << "\n";
    }
    break;

    case 4:
    {
        isSquareFour = true;
        qDebug() << "Will switch on: " << i << "\n";
    }
    break;

    case 5:
    {
        isSquareFive = true;
        qDebug() << "Will switch on: " << i << "\n";
    }
    break;

    case 6:
    {
        isSquareSix= true;
        qDebug() << "Will switch on: " << i << "\n";
    }
    break;

    case 7:
    {
        isSquareSeven = true;
        qDebug() << "Will switch on: " << i << "\n";
    }
    break;

    case 8:
    {
        isSquareEight= true;
        qDebug() << "Will switch on: " << i << "\n";
    }
    break;


    }
}


void Stage::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    PositionRect *rectAt;
    QPointF rectTopLeft;

    try
    {
        rectAt  = dynamic_cast<PositionRect*>(this->itemAt(event->scenePos(), QTransform()));


        if (rectAt)
        {
            gridCheckedPositions.append(rectAt->getPos());

            rectTopLeft = rectAt->rect().topLeft();
            removeItem(rectAt); // initial remove

            if (isCurrentPlayer)
            {
                // add playerTile Here
                Player *playerTile = new Player;
                playerTile->setCurrentPlayer(Player::PlayerOne);

                playerTile->setRect(QRectF(rectTopLeft, QSize(200,200)));
                playerTile->setPen(QColor(Qt::black));

                addItem(playerTile);


                playedGrid[rectAt->getPos()] = playerTile->getCurrentPlayer();
                setSquareBool(rectAt->getPos());


                setCurrentPlayingText("Player Two : X");
                isCurrentPlayer = !isCurrentPlayer;
            }
            else if (!isCurrentPlayer)
            {
                // add playerTile Here
                Player *playerTile = new Player;
                playerTile->setCurrentPlayer(Player::PlayerTwo);

                playerTile->setRect(QRectF(rectTopLeft, QSize(200,200)));
                playerTile->setPen(QColor(Qt::black));

                addItem(playerTile);

                playedGrid[rectAt->getPos()] = playerTile->getCurrentPlayer();
                setSquareBool(rectAt->getPos());

                setCurrentPlayingText("Player One : O's");
                isCurrentPlayer  = !isCurrentPlayer;

            }
        }
        else if (!rectAt)
        {
            throw "Error detetched\n";
        }
    }
    catch (const char *e)
    {
        qDebug() << "Empty rect does not exist " << e << "\n";
    }


    checkState();
    QGraphicsScene::mousePressEvent(event);
}

QString Stage::getCurrentPlayingText() const
{
    return currentPlayingText;
}

void Stage::setCurrentPlayingText(const QString &newCurrentPlayingText)
{
    currentPlayingText = newCurrentPlayingText;
}


// traverse QList and determine if the states: (Win/Lose/Draw)
void Stage::checkState()
{
    // check rows
    if (isSquareZero && isSquareThree && isSquareSix)
    {

        QMapIterator<int, int> i(playedGrid);
        while (i.hasNext())
        {
            i.next();
            qDebug() << i.key() << " : " << i.value() << "\n";
        }

        if ( (playedGrid[0] == playedGrid[3] ) && (playedGrid[3] == playedGrid[6])  )
        {
            qDebug() << "Win state \n";
            this->clear();

            QGraphicsTextItem *text = new QGraphicsTextItem;
            if (playedGrid[0] == 0)
            {
                text->setPlainText("Player One Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            else
            {
                text->setPlainText("Player Two Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            addItem(text);
        }
    }
    else if (isSquareOne && isSquareFour && isSquareSeven)
    {


        if ( (playedGrid[1] == playedGrid[4] ) && (playedGrid[4] == playedGrid[7])  )
        {
            qDebug() << "Win state \n";
            this->clear();

            QGraphicsTextItem *text = new QGraphicsTextItem;
            if (playedGrid[1] == 0)
            {
                text->setPlainText("Player One Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            else
            {
                text->setPlainText("Player Two Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            addItem(text);
        }
    }
    else if (isSquareTwo && isSquareFive && isSquareEight)
    {
        if ( (playedGrid[2] == playedGrid[5] ) && (playedGrid[5] == playedGrid[8])  )
        {
            qDebug() << "Win state \n";
            this->clear();

            QGraphicsTextItem *text = new QGraphicsTextItem;
            if (playedGrid[2] == 0)
            {
                text->setPlainText("Player One Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            else
            {
                text->setPlainText("Player Two Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            addItem(text);
        }
    }


    // check columns
    if (isSquareZero && isSquareOne && isSquareTwo)
    {
        if ( (playedGrid[0] == playedGrid[1] ) && (playedGrid[1] == playedGrid[2])  )
        {
            qDebug() << "Win state \n";
            this->clear();

            QGraphicsTextItem* text = new QGraphicsTextItem;
            if (playedGrid[0] == 0)
            {
                text->setPlainText("Player One Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            else
            {
                text->setPlainText("Player Two Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            addItem(text);

        }
    }
    else if (isSquareThree && isSquareFour && isSquareFive )
    {
        if ( (playedGrid[3] == playedGrid[4] ) && (playedGrid[4] == playedGrid[5])  )
        {
            qDebug() << "Win state \n";
            this->clear();

            QGraphicsTextItem* text = new QGraphicsTextItem;
            if (playedGrid[3] == 0)
            {
                text->setPlainText("Player One Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            else
            {
                text->setPlainText("Player Two Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            addItem(text);


        }
    }
    else if (isSquareSix && isSquareSeven && isSquareEight)
    {
        if ( (playedGrid[6] == playedGrid[7] ) && (playedGrid[7] == playedGrid[8])  )
        {
            qDebug() << "Win state \n";
            this->clear();

            QGraphicsTextItem* text = new QGraphicsTextItem;
            if (playedGrid[6] == 0)
            {
                text->setPlainText("Player One Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            else
            {
                text->setPlainText("Player Two Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            addItem(text);

        }
    }


    // check diagonals
    if (isSquareZero && isSquareFour && isSquareEight)
    {
        if ( (playedGrid[0] == playedGrid[4]) && (playedGrid[4] == playedGrid[8])  )
        {
            qDebug() << "Win state \n";
            this->clear();

            QGraphicsTextItem* text = new QGraphicsTextItem;
            if (playedGrid[0] == 0)
            {
                text->setPlainText("Player One Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            else
            {
                text->setPlainText("Player Two Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            addItem(text);
        }
    }
    else if (isSquareSix && isSquareFour && isSquareTwo)
    {
        if ( (playedGrid[6] == playedGrid[4]) && (playedGrid[4] == playedGrid[2])  )
        {
            qDebug() << "Win state \n";
            this->clear();

            QGraphicsTextItem* text = new QGraphicsTextItem;
            if (playedGrid[6] == 0)
            {
                text->setPlainText("Player One Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            else
            {
                text->setPlainText("Player Two Wins!");
                text->setFont(QFont("Helvetica", 0,2,true) );
                text->setScale(3);
                text->setPos(QPointF(125, 225));
            }
            addItem(text);
        }
    }


    // Draw state
    if (isSquareOne && isSquareTwo && isSquareThree && isSquareFour &&
        isSquareFive && isSquareSix && isSquareSeven && isSquareEight)
    {

        clear();
        QGraphicsTextItem *text = new QGraphicsTextItem;
        text->setPlainText("Players Draw!");
        text->setFont(QFont("Helvetica", 0, 2, true));
        text->setScale(3);
        text->setPos(QPointF(125,225));

        addItem(text);
    }
    // 0 3 6
    // 1 4 7
    // 2 5 8

    return;
}




bool Stage::getIsCurrentPlayer() const
{
    return isCurrentPlayer;
}

void Stage::setIsCurrentPlayer(bool newIsCurrentPlayer)
{
    isCurrentPlayer = newIsCurrentPlayer;
}
