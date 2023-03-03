#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "-----Stream Formatters for Booleans-----" << std::endl;

    std::cout << "No boolalpha (10 == 20): " << (10 == 20) << std::endl;
    std::cout << "No boolalpha (10 == 10): " << (10 == 10) << std::endl; 

    // Set True/False Formatting
    std::cout << std::boolalpha;
    std::cout << "No boolalpha (10 == 20): " << (10 == 20) << std::endl;
    std::cout << "No boolalpha (10 == 10): " << (10 == 10) << std::endl;

    std::cout << std::noboolalpha;
    std::cout << "No boolalpha (10 == 20): " << (10 == 20) << std::endl;
    std::cout << "No boolalpha (10 == 10): " << (10 == 10) << std::endl;

    // Set back to True/False using setf Method
    std::cout.setf(std::ios::boolalpha);
    std::cout << "No boolalpha (10 == 20): " << (10 == 20) << std::endl;
    std::cout << "No boolalpha (10 == 10): " << (10 == 10) << std::endl;

    // Reset the default
    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout << "No boolalpha (10 == 20): " << (10 == 20) << std::endl;
    std::cout << "No boolalpha (10 == 10): " << (10 == 10) << std::endl;

    std::cout << "-----Stream Formatters for Integers-----" << std::endl;
    int num1{ 255 };
    int num2{ -255 };

    // Displaying using different bases
    std::cout << std::dec << num1 << std::endl;
    std::cout << std::hex << num1 << std::endl;
    std::cout << std::oct << num1 << std::endl;

    // Displaying showing the base prefix for hex and oct
    std::cout << std::showbase;
    std::cout << std::dec << num1 << std::endl;
    std::cout << std::hex << num1 << std::endl;
    std::cout << std::oct << num1 << std::endl;

    // Displaying the hex value in uppercase
    std::cout.setf(std::ios::showbase);
    std::cout << std::uppercase;
    std::cout << std::hex << num1 << std::endl;
    std::cout << std::noshowbase;
    std::cout << std::resetiosflags(std::ios::uppercase);

    std::cout << std::showpos << std::dec;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << std::resetiosflags(std::ios::showpos);

    std::cout << "-----Stream Formatters for Floats-----" << std::endl;
    double dub1{ 123456789.987654321 };
    double dub2{ 1234.5678 };
    double dub3{ 1234.0 };

    // Displaying defaults
    std::cout << dub1 << std::endl;
    std::cout << dub2 << std::endl;
    std::cout << dub3 << std::endl;

    std::cout << "---Precision 2---" << std::endl;
    std::cout << std::setprecision(2);
    std::cout << dub1 << std::endl;
    std::cout << dub2 << std::endl;
    std::cout << dub3 << std::endl;

    std::cout << "---Precision 5---" << std::endl;
    std::cout << std::setprecision(5);
    std::cout << dub1 << std::endl;
    std::cout << dub2 << std::endl;
    std::cout << dub3 << std::endl;

    std::cout << "---Precision 9---" << std::endl;
    std::cout << std::setprecision(9);
    std::cout << dub1 << std::endl;
    std::cout << dub2 << std::endl;
    std::cout << dub3 << std::endl;

    std::cout << "---Precision with Fixed---" << std::endl;
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << dub1 << std::endl;
    std::cout << dub2 << std::endl;
    std::cout << dub3 << std::endl;

    std::cout << "---Precision with Scientific---" << std::endl;
    std::cout << std::setprecision(3) << std::scientific;
    std::cout << dub1 << std::endl;
    std::cout << dub2 << std::endl;
    std::cout << dub3 << std::endl;

    std::cout << "---Precision with Scientific and Uppercase---" << std::endl;
    std::cout << std::setprecision(3) << std::scientific << std::uppercase;
    std::cout << dub1 << std::endl;
    std::cout << dub2 << std::endl;
    std::cout << dub3 << std::endl;

    std::cout << "---Precision with Showpos---" << std::endl;
    std::cout << std::setprecision(3) << std::fixed << std::showpos;
    std::cout << dub1 << std::endl;
    std::cout << dub2 << std::endl;
    std::cout << dub3 << std::endl;

    // Back to defaults
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::resetiosflags(std::ios::showpos);

    std::cout << "---Precision with Showpoint---" << std::endl;
    std::cout << std::setprecision(10) << std::showpoint;
    std::cout << dub1 << std::endl;
    std::cout << dub2 << std::endl;
    std::cout << dub3 << std::endl;

    //Back to defaults
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::setprecision(6);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::showpoint);

    std::cout << "*****Stream Formatters*****" << std::endl;
    int num3{ 1234 };
    double dub4{ 1234.5678 };
    std::string hello{ "Hello" };

    // Defaults
    std::cout << num3 << dub4 << hello << std::endl;

    std::cout << "---Set Field---" << std::endl;
    std::cout << std::setw(10) << num3 << dub4 << hello << std::endl;
    std::cout << std::setw(10) << num3 << std::setw(10) << dub4 << std::setw(10) << hello << std::endl;
    std::cout << std::setw(10) << std::left << num3 << std::setw(10) << std::left << dub4 << std::setw(10) << std::left << hello << std::endl;

    std::cout << "---Set Fill---" << std::endl;
    std::cout << std::setfill('-');
    std::cout << std::setw(10) << std::left << num3 << std::setw(10) << std::left << dub4 << std::setw(10) << std::left << hello << std::endl;
    std::cout << std::setw(10) << std::left << std::setfill('*') << num3 << std::setw(10) << std::left << std::setfill('#') << dub4 << std::setw(10) << std::left << std::setfill('&') << hello << std::endl;

    return 0;
}
