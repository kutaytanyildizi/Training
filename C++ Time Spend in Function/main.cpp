#include <iostream>
#include <vector>
#include <chrono>
#include <sstream>
#include <iomanip>
#pragma warning(disable : 4996)

void vecDisplay(const std::vector<int>& numbers);
void arrDisplay(const int numbers[]);
void startingTime(std::string nameOfDataStructure);
void endingTime(std::string nameOfDataStructure);

int main()
{
    std::vector<int> vec = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

    vecDisplay(vec);
    arrDisplay(arr);
}

void vecDisplay(const std::vector<int>& numbers)
{
    startingTime("Vector");
    for (const auto it : numbers)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    endingTime("Vector");
}

void arrDisplay(const int numbers[])
{
    startingTime("Array");
    for (int i = 0; i < 10; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    endingTime("Array");
}

void startingTime(std::string nameOfDataStructure)
{
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    std::tm* utc_time = std::gmtime(&time);
    std::ostringstream time_ss;
    time_ss << std::put_time(utc_time, "%Y-%m-%d %H:%M:%S:") << std::setfill('0') << std::setw(3) << ms.count();
    std::cout << nameOfDataStructure << " Display started at: " << time_ss.str() << std::endl;
}

void endingTime(std::string nameOfDataStructure)
{
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    std::tm* utc_time = std::gmtime(&time);
    std::ostringstream time_ss;
    time_ss << std::put_time(utc_time, "%Y-%m-%d %H:%M:%S:") << std::setfill('0') << std::setw(3) << ms.count();
    std::cout << nameOfDataStructure << " Display ended at : " << time_ss.str() << std::endl;
}
