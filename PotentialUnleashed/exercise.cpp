#include "exercise.h"
#include <QString>

Exercise::Exercise()
    :mName(), mSets(), mReps(), mWeight(), mRir(), mRest(), mProgression()
{

}

Exercise::Exercise(QString name, int sets, int reps, float weight, int rir, int rest,QString progression)
    :mName(name), mSets(sets), mReps(reps), mWeight(weight), mRir(rir), mRest(rest), mProgression(progression)
{

}

QString Exercise::name() const
{
    return mName;
}

void Exercise::setName(const QString &newName)
{
    mName = newName;
}

int Exercise::sets() const
{
    return mSets;
}

void Exercise::setSets(int newSets)
{
    mSets = newSets;
}

int Exercise::reps() const
{
    return mReps;
}

void Exercise::setReps(const int &newReps)
{
    mReps = newReps;
}

float Exercise::weight() const
{
    return mWeight;
}

void Exercise::setWeight(float newWeight)
{
    mWeight = newWeight;
}

int Exercise::rir() const
{
    return mRir;
}

void Exercise::setRir(int newRir)
{
    mRir = newRir;
}

int Exercise::rest() const
{
    return mRest;
}

void Exercise::setRest(int newRest)
{
    mRest = newRest;
}

QString Exercise::progression() const
{
    return mProgression;
}

void Exercise::setProgression(QString newProgression)
{
    mProgression = newProgression;
}

QList<QStandardItem *> Exercise::exerciseToStandardItem()
{

    QStandardItem* nameItem = new QStandardItem(mName);
    QStandardItem* setsItem = new QStandardItem(QString("%1").arg(mSets) );
    QStandardItem* repsItem = new QStandardItem(QString("%1").arg(mReps));
    QStandardItem* weightItem = new QStandardItem(QString("%1").arg(mWeight));
    QStandardItem *rirItem = new QStandardItem(QString("%1").arg(mRir));
    QStandardItem *restItem = new QStandardItem(QString("%1").arg(mRest));
    QStandardItem *progressionItem = new QStandardItem(mProgression);




    QList<QStandardItem*> list;
    list.append(nameItem);
    list.append(setsItem);
    list.append(repsItem);
    list.append(weightItem);
    list.append(rirItem);
    list.append(restItem);
    list.append(progressionItem);

    qDebug() << "Size : " << list.size() << "\n";
    return list;

}
