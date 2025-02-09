#include "createworkoutdialog.h"
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>

#include <QMessageBox>

#include <QDateEdit>
#include <QFontDatabase>

#include <QStandardItemModel>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItem>
#include <QList>
#include <QDate>
#include <QInputDialog>
#include <QDir>

#include "exercise.h"

// ctor
CreateWorkoutDialog::CreateWorkoutDialog(bool createFromTemplate) : mTrainingMap(),
    workout(),
    exerciseDate(),
    createFromTemplate(createFromTemplate)
{
    if (createFromTemplate)
    {
        QVBoxLayout *mainLayout = new QVBoxLayout;
        QLabel *heading = new QLabel(this);
        heading->setText("Please Enter the following: ");
        mainLayout->addWidget(heading);


        mNameLabel = new QLabel(this);
        mNameLabel->setText("Name: ");
        mNameInput = new QLineEdit(this);
        mNameInput->setMaxLength(30);
        mNameLabel->setBuddy(mNameLabel);
        mNameInput->setPlaceholderText("Enter Username");


        mGenderLabel = new QLabel(this);
        mGenderLabel->setText("Gender: ");
        mGenderComboBox = new QComboBox(this);
        mGenderComboBox->addItems(QStringList() << "Male" << "Female");
        mGenderLabel->setBuddy(mGenderComboBox);

        mAgeLabel = new QLabel(this);
        mAgeLabel->setText("Age: ");
        mAgeSpinBox = new QSpinBox(this);
        mAgeSpinBox->setRange(14,50);
        mAgeLabel->setBuddy(mAgeSpinBox);


        mTrainingHistoryLabel = new QLabel(this);
        mTrainingHistoryLabel->setText("Training History: ");
        mTrainingHistoryComboBox = new QComboBox(this);
        mTrainingHistoryComboBox->addItems(QStringList() << "Beginner" << "Intermediate" );
        mTrainingHistoryLabel->setBuddy(mTrainingHistoryComboBox);





        mTrainingDaysLabel = new QLabel(this);
        mTrainingDaysLabel->setText("Training Sessions: ");
        mTrainingSplit = new QComboBox(this);
        mTrainingSplit->addItems(QStringList() << "Minimalist (2 workouts a week)" << "Powerful (3 workouts a week)" );
        mTrainingDaysLabel->setBuddy(mTrainingSplit);

        mCardioSessionLabel = new QLabel(this);
        mCardioSessionLabel->setText("Cardio Sessions: ");
        mCardioSessionComboBox = new QComboBox(this);
        mCardioSessionComboBox->addItems(QStringList() << "0" << "1" << "2" << "3");
        mCardioSessionLabel->setBuddy(mCardioSessionComboBox);



        buildBtn = new QPushButton("Build Program", this);


        formLayout = new QFormLayout;
        formLayout->addRow(mNameLabel, mNameInput);
        formLayout->addRow(mGenderLabel, mGenderComboBox);
        formLayout->addRow(mAgeLabel, mAgeSpinBox);
        formLayout->addRow(mTrainingHistoryLabel, mTrainingHistoryComboBox);
        formLayout->addRow(mTrainingDaysLabel,mTrainingSplit);
        formLayout->addRow(mCardioSessionLabel, mCardioSessionComboBox);


        // Signals and Slots
        connect(buildBtn, SIGNAL(clicked(bool)), this, SLOT(createExerciseObject()));
        connect(mTrainingHistoryComboBox, SIGNAL(activated(int)), this, SLOT(alterTrainingGoal(int)));

        mainLayout->addLayout(formLayout);

        mainLayout->addWidget(buildBtn);

        setLayout(mainLayout);
        setMinimumSize(QSize(480, 250));
        setMaximumSize(QSize(480, 250));
        setWindowTitle("Create Workout From Template");
    }
    else
    {
        // now the user has the ability to create their own workout
        mExerciseName = new QLineEdit(this);
        mExerciseName->setPlaceholderText("Exercise Name: ");

        mSetsLabel = new QLabel(this);
        mSetsLabel->setText("Sets");
        mSetSpinBox = new QSpinBox(this);
        mSetSpinBox->setRange(1,10);

        mRepsLabel = new QLabel(this);
        mRepsLabel->setText("Reps");
        mRepSpinBox = new QSpinBox(this);
        mRepSpinBox->setRange(1,100);

        mWeightLabel = new QLabel(this);
        mWeightLabel->setText("Weight (Kilos)");
        mWeightSpinBox = new QDoubleSpinBox(this);
        mWeightSpinBox->setRange(0,500);


        mRIRLabel = new QLabel(this);
        mRIRLabel->setText("RIR (Reps in Reserve)");
        mRIRSpinBox = new QSpinBox(this);
        mRIRSpinBox->setRange(0,20);

        mRestLabel = new QLabel(this);
        mRestLabel->setText("Rest (seconds)");
        mRestSpinBox = new QSpinBox(this);
        mRestSpinBox->setRange(0,500);

        mProgression = new QLabel(this);
        mProgression->setText("Progression");
        mProgressionComboBox = new QComboBox(this);
        mProgressionComboBox->addItems(QStringList() << "DDP" << "Straight Sets" << "1 Rep in the Tank" << "Giant Set"
                                                     << "3's" << "3 week wave" << "6 week wave" << "Burn set");


        mDateLabel = new QLabel(this);
        mDateLabel->setText("Date");
        mDateEdit = new QDateEdit(QDate::currentDate(), this);
        mDateEdit->setCalendarPopup(true);

        mAddExercise = new QPushButton("Add Exercise", this);

        mModel = new QStandardItemModel(this);
        QStringList columns;
        columns << "Name" << "Sets" << "Reps" << "Weight" << "RIR" << "Rest" << "Progression" << "Date";
        mModel->setHorizontalHeaderLabels(columns);

        mTable = new QTableView(this);
        mTable->setModel(mModel);
        mTable->horizontalHeader()->setStretchLastSection(true);

        for (int i=0;i<8;i++)
        {
            mTable->setColumnWidth(i, (width()/9));
        }

        mConfirmButton = new QPushButton("Confirm Workout",this);


        QVBoxLayout *layoutOne = new QVBoxLayout;
        layoutOne->addWidget(mExerciseName);
        layoutOne->addWidget(mSetsLabel);
        layoutOne->addWidget(mSetSpinBox);
        layoutOne->addWidget(mRepsLabel);
        layoutOne->addWidget(mRepSpinBox);
        layoutOne->addWidget(mWeightLabel);
        layoutOne->addWidget(mWeightSpinBox);
        layoutOne->addWidget(mRIRLabel);
        layoutOne->addWidget(mRIRSpinBox);
        layoutOne->addWidget(mRestLabel);
        layoutOne->addWidget(mRestSpinBox);
        layoutOne->addWidget(mProgression);
        layoutOne->addWidget(mProgressionComboBox);
        layoutOne->addWidget(mDateLabel);
        layoutOne->addWidget(mDateEdit);
        QSpacerItem *spacer = new QSpacerItem(20,60);
        layoutOne->addSpacerItem(spacer);
        layoutOne->addWidget(mAddExercise);


        mExerciseName->setFocus();

        QHBoxLayout *layoutTwo = new QHBoxLayout;
        layoutTwo->addLayout(layoutOne);
        layoutTwo->addWidget(mTable);



        QVBoxLayout *primeLayout = new QVBoxLayout;
        primeLayout->addLayout(layoutTwo);
        primeLayout->addWidget(mConfirmButton);


        // Signals and Slots
        connect(mAddExercise, SIGNAL(clicked(bool)), this, SLOT(addExerciseToWorkout()));
        connect(mConfirmButton, SIGNAL(clicked()), this, SLOT(confirmWorkout()));

        setLayout(primeLayout);
        setWindowTitle("Create Workout");
        setMinimumWidth(1200);


    }




}


// ensure we have a username in the template workout form
bool CreateWorkoutDialog::validateForm()
{
    return (!mNameInput->text().isEmpty());
}

// data used to create workout from template
void CreateWorkoutDialog::createExerciseObject()
{
    qDebug() << validateForm() << "\n";

    if (validateForm())
    {
        // this is how I propagate to the main window
        mTrainingMap["Username"] = mNameInput->text();
        mTrainingMap["Gender"] = mGenderComboBox->currentText();
        mTrainingMap["Age"] = QString("%1").arg(mAgeSpinBox->value()) ;
        mTrainingMap["TrainingHistory"] = mTrainingHistoryComboBox->currentText() ;
        mTrainingMap["TrainingSplit"] = mTrainingSplit->currentText();
        mTrainingMap["CardioSession"] = mCardioSessionComboBox->currentText() ;


        // If I have data I can now populate the Weekly workout

        // emit something here
        emit submitTemplateArguments(mTrainingMap);
        close();

    }
    else
    {
        QMessageBox::information(this, "Missing Data", "Please ensure all fields are filled");
    }

}

// User created workouts
void CreateWorkoutDialog::addExerciseToWorkout()
{
    if (mExerciseName->text().isEmpty())
    {
        QMessageBox::information(this, "Missing Fields", "Please ensure all fields are filled before adding an exercise");
    }
    else
    {
        // Now I grab all the data I need
        QString exerciseName = mExerciseName->text();
        QString numOfSets = QString("%1").arg(mSetSpinBox->value());
        QString numOfReps = QString("%1").arg(mRepSpinBox->value());
        QString weight = QString("%1").arg(mWeightSpinBox->value());
        QString rir = QString("%1").arg(mRIRSpinBox->value());
        QString progression = mProgressionComboBox->currentText();
        QString date = QString("%1").arg(mDateEdit->date().toString());
        qDebug() << "Date: " << date << "\n";
        QString rest = QString("%1").arg(mRestSpinBox->value());
        Exercise *exercise = new Exercise(exerciseName,mSetSpinBox->value(), mRepSpinBox->value(),mWeightSpinBox->value(), mRIRSpinBox->value(),
                                          mRestSpinBox->value(), mProgressionComboBox->currentText());



        QStandardItem *nameItem = new QStandardItem(exerciseName);
        QStandardItem *setsItem = new QStandardItem(numOfSets);
        QStandardItem *repsItem = new QStandardItem(numOfReps);
        QStandardItem *weightItem = new QStandardItem(weight);
        QStandardItem *rirItem = new QStandardItem(rir);
        QStandardItem *progressionItem = new QStandardItem(progression);
        QStandardItem *dateItem = new QStandardItem(date);
        QStandardItem *restItem = new QStandardItem(rest);

        QStandardItem *eDate = new QStandardItem(mDateEdit->date().toString()); // cannot add the same SI to the same place

        int row = mModel->rowCount();
        mModel->insertRow(row, QList<QStandardItem*>() << nameItem << setsItem << repsItem << weightItem << rirItem << restItem << progressionItem << dateItem );

        workout.append(exercise);
        exerciseDate.append(eDate);


        mExerciseName->clear();
    }



}

// prevent a beginner from selecting program types they should not be able to.
void CreateWorkoutDialog::alterTrainingGoal(int index)
{
    if (mTrainingHistoryComboBox->itemText(index) == "Beginner")
    {
        mTrainingSplit->clear();
        mTrainingSplit->addItems(QStringList() << "Minimalist (2 workouts a week)" << "Powerful (3 workouts a week)"  );
    }
    else
    {
        mTrainingSplit->clear();
        mTrainingSplit->addItems(QStringList() << "Absolute Minimalist (2 workouts a week)" << "Become Powerful (3 workouts a week)"
                                               << "Gaur (4 workouts a week)" << "Invincible under the sun (4 workouts a week)");
    }
}


// confirm btn for user created workouts -> Should write to database
void CreateWorkoutDialog::confirmWorkout()
{
    if (mModel->rowCount() > 0 && !createFromTemplate)
    {
        bool ok;
        QString workoutName = QInputDialog::getText(this, "New Workout", "Workout Name",
                                             QLineEdit::Normal, "", &ok);

        if (ok && !workoutName.isEmpty() )
        {
            qDebug() << "Emit submit workout\n";
            emit submitWorkout(workout, exerciseDate, workoutName);
            mModel->removeRows(0,mModel->rowCount());
            close();
        }
        else
        {

            QMessageBox::warning(this, "Error", "Please ensure workout name is set");

        }

    }


}


CreateWorkoutDialog::~CreateWorkoutDialog()
{
    qDeleteAll(workout);
    workout.clear();


}
