#include "utlity.h"

Utlity::Utlity() {}

int Utlity::checkDateDistance(QDate *d1, int dayOfWeek)
{
    return ( abs(d1->dayOfWeek() - dayOfWeek ) );
}
