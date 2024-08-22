#include "primeworker.h"

primeWorker::primeWorker(int start, int end) : m_start(start), m_end(end)
{

}

void primeWorker::process()
{
    for (int number = m_start;number<=m_end;number++)
    {
        if (isPrime(number))
        {
            qDebug() << number << " is a prime number ";
        }
    }

    emit finished(); // when done let this signal be heared
}

bool primeWorker::isPrime(int number)
{
    if (number <= 1) {return false;}
    if (number == 2) {return true;}
    for (int i=3;i<qSqrt(number); i+=2)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;

}
