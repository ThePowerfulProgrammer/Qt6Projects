#ifndef SCAN_H
#define SCAN_H
#include <QObject>



/*
Write the class definition of the Scan class, which is to be run as a thread, that will be
used to count the number of times vegan chocolates is mentioned in a piece of text. The
filename to scan will be passed to the class instance, and the number of occurrences
should be returned to the calling function once the scan is complete. Include all
functionality that would be required so that it conforms to best practice. Use function and
variable names that will make it clear what the purpose of the function or variable is

Basically we need the slot to act as a function as the calling function that returns the
number of occurences is the signal returnCount

*/

class Scan : public QObject
{
    Q_OBJECT
public:
    explicit Scan(QString fName);

public slots:
    // when working with thread we need slots to communicate with slots, ie: emit the slot
    void countVegan(); // will find the Vegan tags in the doc and emit a signal

signals:
    void returnCount(int count); // return result of scan
    void finished(); // indicates the end of countVegan and delete thread/worker



private:
    QString m_fileName;
};

#endif // SCAN_H
