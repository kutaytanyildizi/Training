#ifndef _CLIENT_H_
#define _CLIENT_H_
#include "Observer.h"
#include "Weather.h"
#include <iostream>

class Client : public Observer
{
private:
    Weather &weather;
    static int numberOfClients;
    int idNumber;

public:
    Client(Weather &othWeather);
    ~Client();
    void update(float temp, float humidity, float pressure) override;
    void removeFromList();
    int getIdNumber() const;

};

#endif
