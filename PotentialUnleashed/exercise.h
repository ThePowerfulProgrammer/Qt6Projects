#ifndef EXERCISE_H
#define EXERCISE_H
#include <QList>
#include <QObject>
#include <QStandardItem>

class QString;


class Exercise : public QObject
{
    Q_OBJECT

public:
    Exercise();
    Exercise(QString name, int sets, int reps, float weight, int rir, int rest,QString progression);

    QString name() const;
    void setName(const QString &newName);

    int sets() const;
    void setSets(int newSets);

    int reps() const;
    void setReps(const int &newReps);

    float weight() const;
    void setWeight(float newWeight);

    int rir() const;
    void setRir(int newRir);

    int rest() const;
    void setRest(int newRest);

    QString progression() const;
    void setProgression(QString newProgression);

    QList<QStandardItem*> exerciseToStandardItem();


private:
    QString mName;
    int mSets;
    int mReps; // always init to the size of sets
    float mWeight;
    int mRir; // Reps in reserve easier to understand
    int mRest;
    QString mProgression;


};

#endif // EXERCISE_H
