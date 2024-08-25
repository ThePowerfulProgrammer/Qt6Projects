#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H

#include <QObject>
#include <QDebug>
#include <QStringList>

class PrimeFinder : public QObject
{
    Q_OBJECT
public:
    explicit PrimeFinder(int threadNumber,int start, int end);

    QStringList getPrimeList() const;
    void setPrimeList(const QStringList &newPrimeList);

    int threadNumber() const;
    void setThreadNumber(int newThreadNumber);

public slots:
    void process();

signals:
    void finished(int threadNumber);
    void primeFound(int threadNumber,int primeNumber);

private:
    int m_threadNumber;
    int m_start;
    int m_end;
    QStringList primeList;

    bool isPrime(int number);



signals:
};

#endif // PRIMEFINDER_H
