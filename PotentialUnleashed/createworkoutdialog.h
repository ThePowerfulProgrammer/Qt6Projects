#ifndef CREATEWORKOUTDIALOG_H
#define CREATEWORKOUTDIALOG_H

#include <QDialog>
#include <QObject>
#include <QMap>

class QStandardItemModel; // data
class QStandardItem;
class QTableView; // presentation
class QLineEdit;
class QSpinBox;
class QDoubleSpinBox;
class QComboBox;
class QLabel;
class QPushButton;
class QFormLayout;
class QDateEdit;
class Exercise;

class CreateWorkoutDialog : public QDialog
{
    Q_OBJECT
public:
    CreateWorkoutDialog(bool createFromTemplate=false);

    ~CreateWorkoutDialog();
    bool validateForm();

public slots:

    void createExerciseObject();
    void addExerciseToWorkout();
    void alterTrainingGoal(int index);


    void confirmWorkout();

signals:
    void submitWorkout(QList<Exercise*>, QList<QStandardItem*>, QString);
    void submitTemplateArguments(QMap<QString,QString>); // and then the main window will decide what data to add or do I do it here?



private:
    bool createFromTemplate;

    QLabel *mNameLabel;
    QLineEdit *mNameInput;

    QLabel *mGenderLabel;
    QComboBox *mGenderComboBox;

    QLabel *mAgeLabel;
    QSpinBox *mAgeSpinBox;

    QLabel *mTrainingHistoryLabel;
    QComboBox *mTrainingHistoryComboBox;



    QLabel *mTrainingDaysLabel;
    QComboBox *mTrainingSplit;

    QLabel *mCardioSessionLabel;
    QComboBox *mCardioSessionComboBox;
    QPushButton *buildBtn;

    QFormLayout *formLayout;
    QMap<QString, QString> mTrainingMap;



    // below are members used to create dialog if user wants to create workout from Scratch
    QLineEdit *mExerciseName;
    QLabel *mSetsLabel;
    QSpinBox *mSetSpinBox;
    QLabel *mRepsLabel;
    QSpinBox *mRepSpinBox;
    QLabel *mWeightLabel;
    QDoubleSpinBox *mWeightSpinBox;
    QLabel *mRIRLabel;
    QSpinBox *mRIRSpinBox;
    QLabel *mRestLabel;
    QSpinBox *mRestSpinBox;
    QLabel *mProgression;
    QComboBox *mProgressionComboBox;
    QLabel *mDateLabel;
    QDateEdit *mDateEdit;
    QPushButton *mAddExercise;

    QStandardItemModel *mModel;
    QTableView *mTable;
    QPushButton *mConfirmButton;


    // actual workout exercises
    QList<Exercise*> workout;
    QList<QStandardItem*> exerciseDate;


};

#endif // CREATEWORKOUTDIALOG_H
