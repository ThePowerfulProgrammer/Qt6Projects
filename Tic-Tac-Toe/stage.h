#ifndef STAGE_H
#define STAGE_H

#include <QGraphicsScene>
#include <QMap>

class PositionRect;
class QGraphicsSceneMouseEvent;
class QGraphicsPixmapItem;
class Player;
class QString;
class QTimer;



class Stage : public QGraphicsScene
{
public:
    explicit Stage(QObject *parent = nullptr);

    // QGraphicsScene interface
    bool getIsCurrentPlayer() const;
    void setIsCurrentPlayer(bool newIsCurrentPlayer);

    QString getCurrentPlayingText() const;
    void setCurrentPlayingText(const QString &newCurrentPlayingText);


    void setSquareBool(int i);

    void checkState();


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);



private:
    bool isCurrentPlayer;
    QString currentPlayingText;

    QList<int> gridCheckedPositions;
    QMap<int, int> playedGrid;


    bool isSquareZero;
    bool isSquareOne;
    bool isSquareTwo;
    bool isSquareThree;
    bool isSquareFour;
    bool isSquareFive;
    bool isSquareSix;
    bool isSquareSeven;
    bool isSquareEight;



};

#endif // STAGE_H
