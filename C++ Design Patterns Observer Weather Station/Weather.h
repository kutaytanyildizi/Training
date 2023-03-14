#ifndef _WEATHER_H_
#define _WEATHER_H_
#include "Subject.h"
#include "Observer.h"
#include <iostream>
#include <vector>
#include <algorithm>

class Weather : public Subject
{
private:
    std::vector<Observer *> observers;
    float temp;
    float humidity;
    float pressure;

public:
    void registerObserver(Observer *observer) override;
    void removeObserver(Observer *observer) override;
    void notifyObservers() override;
    void setState(float temp, float humidity, float pressure);
};

#endif
