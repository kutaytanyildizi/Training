#include <iostream>

class DivideByZeroException{};
class NegativeValueException{};

double calculateKPL(double kilometers, double liters)
{
    if (liters == 0)
    {
        throw DivideByZeroException();
    }
    if (kilometers < 0 || liters < 0)
    {
        throw NegativeValueException();
    }
    return (kilometers / liters);
}

int main()
{
    double kilometers{};
    double liters{};
    double kilometersPerLiters{};

    std::cout << "Enter the kilometers driven : ";
    std::cin >> kilometers;
    std::cout << "Enter the liters used : ";
    std::cin >> liters;

    try
    {
        kilometersPerLiters = calculateKPL(kilometers, liters);
        std::cout << "Result : " << kilometersPerLiters << std::endl;
    }
    catch(const DivideByZeroException &ex)
    {
        std::cerr << "Sorry you can't divide by zero." << std::endl;
    }
    catch (const NegativeValueException &ex)
    {
        std::cerr << "Sorry, one of your parameters is negative." << std::endl;
    }

    return 0;
}
