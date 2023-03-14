#ifndef _OBSERVER_H
#define _OBSERVER_H

class Observer
{
public:
    virtual void update(float temp, float humidity, float pressure) = 0;
};

#endif
