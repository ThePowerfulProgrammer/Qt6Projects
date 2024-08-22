#ifndef PRIMEWORKER_H
#define PRIMEWORKER_H

#include <QObject>
#include <QDebug>

class primeWorker : public QObject
{
    Q_OBJECT
public:
    explicit primeWorker(int start, int end);

public slots:
    void process();

signals:
    void finished();

private:
    int m_start;
    int m_end;

    bool isPrime(int number);


signals:
};

#endif // PRIMEWORKER_H
