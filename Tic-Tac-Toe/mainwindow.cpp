#include <QStatusBar>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QVBoxLayout>

#include "mainwindow.h"
#include "stage.h"

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags)
{


    stage = new Stage(this);



    QGraphicsView *view = new QGraphicsView(this);
    view->setMinimumSize(QSize(650,650));
    view->setScene(stage);

    bar = new QStatusBar();
    bar->showMessage("Game active");

    setCentralWidget(view);
    setStatusBar(bar);

    setMinimumSize(QSize(650,650));
    setMaximumSize(QSize(650,650)); // each indiviual matrix entry will be a square

    setWindowTitle("Tic-Tac-Toe");

}


