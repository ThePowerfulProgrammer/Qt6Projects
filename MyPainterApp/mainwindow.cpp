#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QSpinBox>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    canvas = new Canvas(this);
    setCentralWidget(canvas);

    // Main Window
    QLabel  *penWidthLabel = new QLabel("Draw Width", this);
    QSpinBox *penWidthSpinBox = new QSpinBox(this);
    penWidthSpinBox->setMinimum(1);
    penWidthSpinBox->setMaximum(15);


    QLabel *fillClrLabel = new QLabel("Fill Color", this);
    fillClrBtn = new QPushButton(this);

    QLabel *penClrLabel = new QLabel("Pen Colour", this);
    penClrBtn = new QPushButton(this);

    fillCheckBox = new QCheckBox("Fill Shape", this);

    // Tool bar
    QPushButton *rectBtn = new QPushButton(this);
    rectBtn->setIcon(QIcon(":/images/Rectangle.png"));

    QPushButton *penBtn = new QPushButton(this);
    penBtn->setIcon(QIcon(":/images/Pen.png"));

    QPushButton *ellipseBtn = new QPushButton(this);
    ellipseBtn->setIcon(QIcon(":/images/Circle.png"));

    QPushButton *eraserBtn = new QPushButton(this);
    eraserBtn->setIcon(QIcon(":/images/Craser.png"));

    // S && S
    connect(penWidthSpinBox, SIGNAL(valueChanged()), this, SLOT(penWidthChange(int)));
    connect(penClrBtn, SIGNAL(clicked()), this, SLOT(changePenColor()));
    connect(fillClrBtn, SIGNAL(clicked()), this, SLOT(changeFillColor()));
    connect(fillCheckBox, SIGNAL(clicked()), this, SLOT(changeFillProperty()));

    QToolBar *mainToolBar = new QToolBar(this);
    mainToolBar->addWidget(penWidthLabel);
    mainToolBar->addWidget(penWidthSpinBox);
    mainToolBar->addSeparator();
    mainToolBar->addWidget(penClrLabel);
    mainToolBar->addWidget(penClrBtn);
    mainToolBar->addWidget(fillClrLabel);
    mainToolBar->addWidget(fillClrBtn);
    mainToolBar->addWidget(fillCheckBox);
    mainToolBar->addSeparator();
    mainToolBar->addWidget(penBtn);
    mainToolBar->addWidget(rectBtn);
    mainToolBar->addWidget(ellipseBtn);
    mainToolBar->addWidget(eraserBtn);

    addToolBar(mainToolBar);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::penWidthChange(int width)
{

}

void MainWindow::changePenColor()
{

}

void MainWindow::changeFillColor()
{

}

void MainWindow::changeFillProperty()
{

}
