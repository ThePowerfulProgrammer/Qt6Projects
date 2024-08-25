#include "PrimeFinder.h"

PrimeFinder::PrimeFinder(int threadNumber,int start, int end) : m_threadNumber(threadNumber),m_start(start), m_end(end), primeList()
{

}

void PrimeFinder::process()
{
    for (int number = m_start;number<=m_end;number++)
    {
        if (isPrime(number))
        {
            emit primeFound(m_threadNumber,number);
            qDebug() << number << " is a prime number ";
            primeList.append(QString::number(number));
        }
    }

    emit finished(m_threadNumber); // when done let this signal be heared
}

int PrimeFinder::threadNumber() const
{
    return m_threadNumber;
}

void PrimeFinder::setThreadNumber(int newThreadNumber)
{
    m_threadNumber = newThreadNumber;
}

QStringList PrimeFinder::getPrimeList() const
{
    return primeList;
}

void PrimeFinder::setPrimeList(const QStringList &newPrimeList)
{
    primeList = newPrimeList;
}

bool PrimeFinder::isPrime(int number)
{
    if (number <= 1) return false;          // Numbers less than 2 are not prime
    if (number == 2) return true;           // 2 is the only even prime number
    if (number % 2 == 0) return false;      // Exclude all other even numbers

    for (int i = 3; i * i <= number; i += 2)
    {
        if (number % i == 0)
        {
            return false;                   // Not a prime if divisible by any i
        }
    }
    return true;                            // If no divisors, it's prime
}

