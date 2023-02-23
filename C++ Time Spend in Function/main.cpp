#include <iostream>
#include <vector>
#include <chrono>
#include <sstream>
#include <iomanip>

void vecDisplay(const std::vector<int> &numbers);
void arrDisplay(const int numbers[]);

int main()
{
    std::vector<int> vec = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    vecDisplay(vec);
    arrDisplay(arr);
}

void vecDisplay(const std::vector<int> &numbers)
{
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    std::tm* utc_time = std::gmtime(&time);
    std::ostringstream time_ss;
    time_ss << std::put_time(utc_time, "%Y-%m-%d %H:%M:%S:") << std::setfill('0') << std::setw(3) << ms.count();
    std::cout << "Vector Display started at: " << time_ss.str() << std::endl;
    for(const auto it: numbers)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    now = std::chrono::system_clock::now();
    time = std::chrono::system_clock::to_time_t(now);
    ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    utc_time = std::gmtime(&time);
    time_ss.str("");
    time_ss << std::put_time(utc_time, "%Y-%m-%d %H:%M:%S:") << std::setfill('0') << std::setw(3) << ms.count();
    std::cout << "Vector Display ended at: " << time_ss.str() << std::endl;
}

void arrDisplay(const int numbers[])
{
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    std::tm* utc_time = std::gmtime(&time);
    std::ostringstream time_ss;
    time_ss << std::put_time(utc_time, "%Y-%m-%d %H:%M:%S:") << std::setfill('0') << std::setw(3) << ms.count();
    std::cout << "Array Display started at: " << time_ss.str() << std::endl;
    for(int i = 0; i < 10; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    now = std::chrono::system_clock::now();
    time = std::chrono::system_clock::to_time_t(now);
    ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    utc_time = std::gmtime(&time);
    time_ss.str("");
    time_ss << std::put_time(utc_time, "%Y-%m-%d %H:%M:%S:") << std::setfill('0') << std::setw(3) << ms.count();
    std::cout << "Array Display ended at: " << time_ss.str() << std::endl;
}