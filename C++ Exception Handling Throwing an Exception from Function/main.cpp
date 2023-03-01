#include <iostream>

double calculateAverage(double sum, double total);

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
        kilometersPerLiters = calculateAverage(kilometers, liters);
        std::cout << "Result : " << kilometersPerLiters << std::endl;
    }

    catch (int& err)
    {
        std::cerr << "Sorry, you can't divide by zero." << std::endl;
    }

    return 0;
}

double calculateAverage(double sum, double total)
{
    if (total == 0)
    {
        throw 0;
    }
    return static_cast<double> (sum / total);
}