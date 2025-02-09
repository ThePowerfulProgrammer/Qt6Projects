#ifndef WORKOUT_H
#define WORKOUT_H

#include "exercise.h"
#include <QList>
#include <QString>

class Workout
{
public:
    Workout();

private:

    QList<QString> upperBodyCompoundMovementsPush;
    QList<QString> upperBodyCompoundMovementsPull;

    QList<QString> upperBodyIsolationTriceps;


};

#endif // WORKOUT_H
