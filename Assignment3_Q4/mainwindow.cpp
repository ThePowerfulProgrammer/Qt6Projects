#include "MainWindow.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QStringList>
#include <QTextStream>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    startLineEdit = new QLineEdit(this);
    startLineEdit->setPlaceholderText("")

    threadsSpinBox->setRange(1, 4);
    threadsSpinBox->setValue(1);

    layout->addWidget(startLineEdit);
    layout->addWidget(endLineEdit);
    layout->addWidget(threadsSpinBox);
    layout->addWidget(startButton);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(startButton, &QPushButton::clicked, this, &MainWindow::startFindingPrimes);
}

MainWindow::~MainWindow()
{
    cleanupThreads();
}

void MainWindow::startFindingPrimes()
{
    cleanupThreads();

    bool okStart, okEnd;
    int start = startLineEdit->text().toInt(&okStart);
    int end = endLineEdit->text().toInt(&okEnd);
    int threadCount = threadsSpinBox->value();

    if (!okStart || !okEnd || start > end) {
        QMessageBox::warning(this, "Input Error", "Please enter valid start and end numbers.");
        return;
    }

    int rangePerThread = (end - start + 1) / threadCount;
    int remainingRange = (end - start + 1) % threadCount;

    for (int i = 0; i < threadCount; ++i) {
        int rangeStart = start + i * rangePerThread;
        int rangeEnd = rangeStart + rangePerThread - 1;

        if (i == threadCount - 1) {
            rangeEnd += remainingRange;
        }

        PrimeFinder *thread = new PrimeFinder(rangeStart, rangeEnd);
        threads.append(thread);

        connect(thread, &PrimeFinder::primesFound, this, &MainWindow::displayPrimes);
        QTextEdit *textEdit = new QTextEdit(this);
        textEdit->setWindowTitle(QString("Thread %1").arg(i + 1));
        textEdit->show();
        threadWindows[thread] = textEdit;

        thread->start();
    }
}

void MainWindow::displayPrimes(const QList<int>& primes)
{
    PrimeFinder *thread = qobject_cast<PrimeFinder*>(sender());
    if (thread) {
        QTextEdit *textEdit = threadWindows.value(thread);
        if (textEdit) {
            QStringList primeStrings;
            for (int prime : primes) {
                primeStrings << QString::number(prime);
            }
            textEdit->append(primeStrings.join(", "));
        }
    }
}

void MainWindow::cleanupThreads()
{
    for (PrimeFinder *thread : threads) {
        thread->quit();
        thread->wait();
        delete thread;
    }
    threads.clear();
    for (QTextEdit *textEdit : threadWindows) {
        textEdit->close();
    }
    threadWindows.clear();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    cleanupThreads();
    event->accept();
}
