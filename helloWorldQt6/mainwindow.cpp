#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *btn = new QPushButton;
    btn->setText("Click me");

    QHBoxLayout *hlayout = new QHBoxLayout(ui->centralwidget);

    hlayout->addWidget(btn);



}

MainWindow::~MainWindow()
{
    delete ui;
}
