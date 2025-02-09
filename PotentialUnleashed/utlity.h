#ifndef UTLITY_H
#define UTLITY_H
#include <QDate>

class Utlity
{
public:
    Utlity();

    static int checkDateDistance(QDate *d1, int dayOfWeek);
};

#endif // UTLITY_H
