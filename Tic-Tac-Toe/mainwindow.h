#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>


class StatusBar;
class QGraphicsView;
class QGraphicsScene;
class QGraphicsRectItem;
class QVBoxLayout;
class Stage;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent=nullptr,Qt::WindowFlags flags = Qt::WindowFlags() );

private:
    QStatusBar *bar;
    Stage *stage;
};

#endif // MAINWINDOW_H
