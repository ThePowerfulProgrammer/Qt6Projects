#include "primeworker.h"

primeWorker::primeWorker(int threadNumber,int start, int end) : m_threadNumber(threadNumber),m_start(start), m_end(end), primeList()
{

}

void primeWorker::process()
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

int primeWorker::threadNumber() const
{
    return m_threadNumber;
}

void primeWorker::setThreadNumber(int newThreadNumber)
{
    m_threadNumber = newThreadNumber;
}

QStringList primeWorker::getPrimeList() const
{
    return primeList;
}

void primeWorker::setPrimeList(const QStringList &newPrimeList)
{
    primeList = newPrimeList;
}

bool primeWorker::isPrime(int number)
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

