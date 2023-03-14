#include "Weather.h"

void Weather::registerObserver(Observer *observer)
{
    observers.push_back(observer);
}

void Weather::removeObserver(Observer *observer)
{
    auto it = (std::find(observers.begin(), observers.end(), observer));
    if(it != observers.end())
    {
        observers.erase(it);
    }
}

void Weather::notifyObservers()
{
    for(auto *it : observers)
    {
        it->update(this->temp, this->humidity, this->pressure);
    }
}

void Weather::setState(float temp, float humidity, float pressure)
{
    this->temp = temp;
    this->humidity = humidity;
    this->pressure = pressure;
    notifyObservers();
}
