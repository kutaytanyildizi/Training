#include <iostream>
#include "Client.h"
#include "Weather.h"

int main()
{
    Weather weatherStation;
    Client *client1;
    Client *client2;
    Client *client3;
    Client *client4;


    client1 = new Client(weatherStation);
    client2 = new Client(weatherStation);
    client3 = new Client(weatherStation);
    client4 = new Client(weatherStation);

    weatherStation.setState(45, 12, 3.9);

    weatherStation.removeObserver(client2);

    weatherStation.setState(25.8, 14.5, 30.6);

    client4->removeFromList();

    weatherStation.setState(12, 18, 28.9);

    delete client1;
    delete client2;
    delete client3;
    delete client4;
}

