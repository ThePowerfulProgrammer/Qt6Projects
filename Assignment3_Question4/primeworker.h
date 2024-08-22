#ifndef PRIMEWORKER_H
#define PRIMEWORKER_H

#include <QObject>
#include <QDebug>
#include <QStringList>

class primeWorker : public QObject
{
    Q_OBJECT
public:
    explicit primeWorker(int threadNumber,int start, int end);

    QStringList getPrimeList() const;
    void setPrimeList(const QStringList &newPrimeList);

    int threadNumber() const;
    void setThreadNumber(int newThreadNumber);

public slots:
    void process();

signals:
    void finished();
    void primeFound(int primeNumber);

private:
    int m_threadNumber;
    int m_start;
    int m_end;
    QStringList primeList;

    bool isPrime(int number);



signals:
};

#endif // PRIMEWORKER_H
