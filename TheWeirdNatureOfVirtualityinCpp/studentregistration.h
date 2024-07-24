#ifndef STUDENTREGISTRATION_H
#define STUDENTREGISTRATION_H

#include "registration.h"

class StudentRegistration : public Registration
{
public:
    StudentRegistration(Person a, QString q);

    QString getQualification() const;
    void setQualification(const QString &newQualification);

    QString toString();

    double calculateFee();

private:
    QString qualification;
};

#endif // STUDENTREGISTRATION_H
