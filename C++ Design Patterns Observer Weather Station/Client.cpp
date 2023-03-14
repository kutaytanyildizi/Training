#include "Client.h"

int Client::numberOfClients = 0;

Client::Client(Weather &othWeather) : weather(othWeather)
{
    this->weather.registerObserver(this);
    std::cout << "Client Constructor." << std::endl;
    ++Client::numberOfClients;
    idNumber = Client::numberOfClients;
}

Client::~Client()
{
    std::cout << "Client Destructor." << std::endl;
}

void Client::update(float temp, float humidity, float pressure)
{

    std::cout << "---Client (" << getIdNumber() << ") Data--- \tTemperature: " << temp << "\t Humidity: " << humidity << "\tPressure: " << pressure << std::endl;
}

void Client::removeFromList()
{
    weather.removeObserver(this);
    std::cout << "Client Number " << getIdNumber() << " removed from the list." << std::endl;
}

int Client::getIdNumber() const
{
    return idNumber;
}