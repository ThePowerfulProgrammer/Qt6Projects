#include <QApplication>
#include <QThread>
#include "primeworker.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    primeWorker *worker1 = new primeWorker(1,5);
    primeWorker *worker2 = new primeWorker(6,10);

    QThread *thread1 = new QThread;
    QThread *thread2 = new QThread;

    worker1->moveToThread(thread1);
    worker2->moveToThread(thread2);

    // Using the new syntax
    QObject::connect(thread1, &QThread::started, worker1, &primeWorker::process);
    QObject::connect(worker1, &primeWorker::finished, thread1, &QThread::quit);
    QObject::connect(worker1, &primeWorker::finished, worker1, &QObject::deleteLater);
    QObject::connect(thread1, &QThread::finished, thread1, &QObject::deleteLater);

    QObject::connect(thread2, &QThread::started, worker2, &primeWorker::process);
    QObject::connect(worker2, &primeWorker::finished, thread2, &QThread::quit);
    QObject::connect(worker2, &primeWorker::finished, worker2, &QObject::deleteLater);
    QObject::connect(thread2, &QThread::finished, thread2, &QObject::deleteLater);


    thread1->start();
    thread2->start();

    return a.exec();
}
