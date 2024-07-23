#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canvas.h"
#include <QPushButton>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void penWidthChange(int width);
    void changePenColor();
    void changeFillColor();
    void changeFillProperty();

private:
    Ui::MainWindow *ui;
    Canvas *canvas;
    QPushButton *penClrBtn;
    QPushButton *fillClrBtn;
    QCheckBox *fillCheckBox;
};
#endif // MAINWINDOW_H
