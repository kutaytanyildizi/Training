#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include "Observer.h"

class Subject
{
private:
    virtual void registerObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObservers() = 0;
};

#endif
