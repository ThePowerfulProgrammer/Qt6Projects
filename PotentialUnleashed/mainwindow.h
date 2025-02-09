#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QDate>
#include <QMap>

class QStandardItemModel; // data
class QStandardItem;
class QTableView; // presentation
class QVBoxLayout;
class QMenuBar;
class QMenu;
class QAction;
class QPushButton;
class CreateWorkoutDialog;
class QStandardItem;
class Exercise;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

public slots:
    void createWorkoutFromTemplate();
    void createWorkout();

    void addWorkoutToModel(QList<Exercise*> workout, QList<QStandardItem*> dates, QString workoutName);

    void createWorkoutFromTemplateData(QMap<QString, QString> map);

signals:

private:
    QStandardItemModel *m_Model;
    QTableView *m_TableView;

    QMenuBar *m_MenuBar;
    QMenu *m_Profile;
    QAction *m_Me;
    QAction *m_WorkoutHistory;

    QMenu *m_PotentialUnleashed;
    QMenu *m_NewWorkout;
    QAction *m_CreateNewWorkout;
    QAction *m_CreateFromTemplate;


    QMenu *m_Guides;
    QAction *m_MuscleGain;
    QAction *m_FatLoss;

    QAction *m_Analyse;


    CreateWorkoutDialog* workoutDialog;


    QList<int> testList;
    bool hasNewWorkoutBeenCreated;


};

#endif // MAINWINDOW_H
