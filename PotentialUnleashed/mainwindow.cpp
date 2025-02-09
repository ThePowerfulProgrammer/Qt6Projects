#include "mainwindow.h"
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTableView>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QHeaderView>
#include <QPushButton>
#include <QDate>
#include <QCalendar>
#include "exercise.h"
#include "utlity.h"

#include "createworkoutdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}, hasNewWorkoutBeenCreated(false)
{
    m_Model = new QStandardItemModel(this);

    QStringList columns;
    columns << "Name" << "Sets" << "Reps" << "Weight" << "RIR" << "Rest" << "Progression" << "Date";
    m_Model->setHorizontalHeaderLabels( columns);


    qDebug() << this->width()/4 << "\n";
    m_TableView = new QTableView(this);
    m_TableView->setModel(m_Model);
    for (int i=0;i<7;i++)
    {
        m_TableView->setColumnWidth(i, (width()/9) );
    }

    m_TableView->horizontalHeader()->setStretchLastSection(true);





    m_MenuBar = new QMenuBar(this);

    m_Profile = new QMenu(this);
    m_Profile->setTitle("Profile");

    m_Me = new QAction(this);
    m_Me->setText("Me");
    m_WorkoutHistory = new QAction(this);
    m_WorkoutHistory->setText("Workout History");
    m_Profile->addAction(m_Me);
    m_Profile->addSeparator();
    m_Profile->addAction(m_WorkoutHistory);

    m_MenuBar->addMenu(m_Profile);

    m_PotentialUnleashed = new QMenu(this);

    m_PotentialUnleashed->setTitle("Potential Unleashed");
    m_NewWorkout = new QMenu(this);
    m_NewWorkout->setTitle("New Workout");
    m_CreateNewWorkout = new QAction(this);
    m_CreateNewWorkout->setText("Create New Workout");
    m_CreateFromTemplate = new QAction(this);
    m_CreateFromTemplate->setText("Create from Template");
    m_NewWorkout->addAction(m_CreateNewWorkout);
    m_NewWorkout->addAction(m_CreateFromTemplate);



    m_Guides = new QMenu(this);
    m_Guides->setTitle("Guides");
    m_MuscleGain = new QAction(this);
    m_MuscleGain->setText("Build Muscle");
    m_FatLoss = new QAction(this);
    m_FatLoss->setText("Lose Fat");
    m_Guides->addAction(m_MuscleGain);
    m_Guides->addAction(m_FatLoss);

    m_Analyse = new QAction(this);
    m_Analyse->setText("Analyse");
    m_PotentialUnleashed->addMenu(m_NewWorkout);
    m_PotentialUnleashed->addMenu(m_Guides);
    m_PotentialUnleashed->addSeparator();
    m_PotentialUnleashed->addAction(m_Analyse);

    m_MenuBar->addMenu(m_PotentialUnleashed);

    // Signals and Slots
    connect(m_CreateFromTemplate, SIGNAL(triggered(bool)), this, SLOT(createWorkoutFromTemplate()));
    connect(m_CreateNewWorkout, SIGNAL(triggered(bool)), this, SLOT(createWorkout()) );




    setMenuWidget(m_MenuBar);
    setWindowTitle("Potential Unleashed");
    setCentralWidget(m_TableView);
    setMinimumSize(QSize(650, 434));

}

void MainWindow::createWorkoutFromTemplate()
{
    workoutDialog = new CreateWorkoutDialog(true); // template create button
    workoutDialog->setModal(true);
    connect(workoutDialog, SIGNAL(submitTemplateArguments(QMap<QString,QString>)), this, SLOT(createWorkoutFromTemplateData(QMap<QString,QString>)) );

    workoutDialog->show();


}

void MainWindow::createWorkout()
{
    workoutDialog = new CreateWorkoutDialog();
    workoutDialog->setModal(true);
    connect(workoutDialog, SIGNAL(submitWorkout(QList<Exercise*>,QList<QStandardItem*>,QString))  , this, SLOT(addWorkoutToModel(QList<Exercise*>,QList<QStandardItem*>,QString))   );
    workoutDialog->show();
}



void MainWindow::addWorkoutToModel(QList<Exercise *> workout, QList<QStandardItem *> dates, QString workoutName)
{
    qDebug() << workoutName << "\n";

    workout[0]->exerciseToStandardItem().append(dates[0]);


    int i = 0;
    for (Exercise *ex: workout)
    {

        QList<QStandardItem*> items = ex->exerciseToStandardItem();
        items.append(dates[i]);

        m_Model->insertRow(m_Model->rowCount(), items );
        i +=1;

    }



}

void MainWindow::createWorkoutFromTemplateData(QMap<QString, QString> map)
{
    QMap<QString, QString>::Iterator it;


    if (map["TrainingHistory"] == "Beginner" && (map["TrainingSplit"] == "Minimalist (2 workouts a week)") )
    {

        Exercise *ex1 = new Exercise("Bench Press", 3,5,0,3,120,"1 Rep in the tank");
        Exercise *ex2 = new Exercise("RDL", 3,5,0,3,120,"1 Rep in the tank");
        Exercise *ex3 = new Exercise("Straight Bar Overhand Row", 3, 8, 0, 3, 90, "1 Rep in the tank");
        Exercise *ex4 = new Exercise("V-bar Pushdown", 3, 10,0,3,90, "1 Rep in the tank");
        Exercise *ex5 = new Exercise("Abs", 2,10,0,3,90, "1 Rep in the tank");
        Exercise *ex6 = new Exercise("Squat", 3, 5,0,4,180, "RIR Target");
        Exercise *ex7 = new Exercise("OHP", 3 , 6, 0, 3, 120, "1 Rep in the tank");
        Exercise *ex8 = new Exercise("Lat PullDown", 3, 6, 0, 3, 90, "Straight sets");
        Exercise *ex9 = new Exercise("DB Curl", 2, 10, 0, 3, 90, "Straight sets");
        Exercise *ex10 = new Exercise("Abs", 2, 10, 0, 3, 90, "RIR Target");

        QList<Exercise*> exercises;
        exercises << ex1 << ex2 << ex3 << ex4 << ex5 << ex6 << ex7 << ex8 << ex9 << ex10 ;

        QDate *date = new QDate(QDate::currentDate());

        for (int i=0;i<exercises.size()/2 ; i++)
        {
            QList<QStandardItem*> items = exercises[i]->exerciseToStandardItem();
            QStandardItem *dateItem = new QStandardItem(date->toString());
            items.append(dateItem);
            m_Model->insertRow(m_Model->rowCount(), items );
        }

        // if (date->day() > 4)
        // {
        //     while (date->day() > 4)
        //     {
        //         date->setDate(date->year(), date->month(), date->day()  - 1);
        //     }
        // }
        // else if (date->day() < 4)
        // {
        //     while (date->day() < 4)
        //     {
        //         date->setDate(date->year(), date->month(), date->day() + 1);
        //     }
        // }

        if (date->day() < 6)
        {
            date->setDate(date->year(), date->month(), date->day() + 2);
        }

        for (int i=exercises.size()/2;i<exercises.size(); i++)
        {
            QList<QStandardItem*> items = exercises[i]->exerciseToStandardItem();

            QStandardItem *dateItem = new QStandardItem(date->toString());
            items.append(dateItem);
            m_Model->insertRow(m_Model->rowCount(), items );
        }

        delete date;
        date = nullptr;

    }
    else if (map["TrainingHistory"] == "Beginner" && (map["TrainingSplit"] == "Powerful (3 workouts a week)") )
    {

        Exercise *ex1 = new Exercise("Bench Press", 3,5,0,3,120,"1 Rep in the tank");
        Exercise *ex2 = new Exercise("Barbell Row Overhand", 3,5,0,3,120,"RIR Target");
        Exercise *ex3 = new Exercise("Laying Hamstring Curl", 3, 8, 0, 3, 90, "RIR Target");
        Exercise *ex4 = new Exercise("Lateral Raise", 2, 10,0,3,90, "Straight sets");
        Exercise *ex5 = new Exercise("DB Curl", 2,10,0,3,90, "Straight sets");
        Exercise *ex6 = new Exercise("V-bar Pushdown", 2, 10,0,3,90, "Straight sets");

        Exercise *ex7 = new Exercise("Squat", 3 , 5, 0, 3, 180, "RIR Target");
        Exercise *ex8 = new Exercise("OHP", 3, 5, 0, 3, 120, "RIR Target");
        Exercise *ex9 = new Exercise("Pull ups", 3, 6, 0, 3, 120, "RIR Target");
        Exercise *ex10 = new Exercise("Leg Press", 2, 8, 0, 3, 90, "1 Rep in the tank");
        Exercise *ex11 = new Exercise("Hammer curls", 2, 10, 0, 3, 90, "RIR Target");
        Exercise *ex12 = new Exercise("Abs", 2, 10, 0, 3, 90, "RIR Target");

        Exercise *ex13 = new Exercise("Deadlift", 2 , 4, 0, 4, 180, "RIR Target");
        Exercise *ex14 = new Exercise("Incline Bench Press", 3, 8, 0, 3, 120, "RIR Target");
        Exercise *ex15 = new Exercise("Pause Squat", 2, 4, 0, 5, 120, "RIR Target");
        Exercise *ex16 = new Exercise("Straight Bar Row ", 2, 8, 0, 3, 90, "1 Rep in the tank");
        Exercise *ex17 = new Exercise("Lateral Raise", 2, 8, 0, 3, 90, "RIR Target");
        Exercise *ex18 = new Exercise("Single Arm Cable Tricep Extension", 2, 8, 0, 3, 90, "RIR Target");

        QList<Exercise*> exercises;
        exercises << ex1 << ex2 << ex3 << ex4 << ex5 << ex6 << ex7 << ex8 << ex9 << ex10 << ex11 << ex12 <<
            ex13 << ex14 << ex15 << ex16 << ex17 << ex18;


        QDate *date = new QDate(QDate::currentDate());
        if (date->day() > 1)
        {
            while (date->day() > 1)
            {
                date->setDate(date->year(), date->month(), date->day()  - 1);
            }
        }
        else if (date->day() < 1)
        {
            while (date->day() < 1)
            {
                date->setDate(date->year(), date->month(), date->day() + 1);
            }
        }

        for (int i=0;i<exercises.size()/3 ; i++)
        {
            QList<QStandardItem*> items = exercises[i]->exerciseToStandardItem();
            QStandardItem *dateItem = new QStandardItem(date->toString());
            items.append(dateItem);
            m_Model->insertRow(m_Model->rowCount(), items );
        }

        if (date->day() > 3)
        {
            while (date->day() > 3)
            {
                date->setDate(date->year(), date->month(), date->day()  - 1);
            }
        }
        else if (date->day() < 3)
        {
            while (date->day() < 3)
            {
                date->setDate(date->year(), date->month(), date->day() + 1);
            }
        }


        for (int i=exercises.size()/3;i<exercises.size()/1.5; i++)
        {
            QList<QStandardItem*> items = exercises[i]->exerciseToStandardItem();
            QStandardItem *dateItem = new QStandardItem(date->toString());
            items.append(dateItem);
            m_Model->insertRow(m_Model->rowCount(), items );
        }

        if (date->day() > 5)
        {
            while (date->day() > 5)
            {
                date->setDate(date->year(), date->month(), date->day()  - 1);
            }
        }
        else if (date->day() < 5)
        {
            while (date->day() < 5)
            {
                date->setDate(date->year(), date->month(), date->day() + 1);
            }
        }


        for (int i=exercises.size()/1.5;i<exercises.size(); i++)
        {
            QList<QStandardItem*> items = exercises[i]->exerciseToStandardItem();
            QStandardItem *dateItem = new QStandardItem(date->toString());
            items.append(dateItem);
            m_Model->insertRow(m_Model->rowCount(), items );
        }

        delete date;
        date = nullptr;

    }



}


