#include <iostream>
#include <array>
#include <algorithm>
#include <numeric> //for more algorithm like accumulate

void displayArr(const std::array<int, 5>& arr);
void basicArrFunctions();
void arrFillAndSwap();
void arrWithPointer();
void arrSortFunc();
void arrMinAndMax();
void arrAdjacentFind();
void arrAccumulate();
void arrCount();

int main()
{ 
    basicArrFunctions();
    arrFillAndSwap();
    arrWithPointer();
    arrSortFunc();
    arrMinAndMax();
    arrAdjacentFind();
    arrAccumulate();
    arrCount();

 	return 0;
}

void displayArr(const std::array<int, 5>& arr)
{
    std::cout << "[ ";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr.at(i) << " ";
    }
    std::cout << "]" << std::endl;
}

void basicArrFunctions()
{
    std::cout << "\n=====================" << std::endl;
    std::cout << "Basic Array Functions" << std::endl;

    std::array<int, 5> arr1{ { 1, 2, 3, 4, 5 } }; //This decleration is for C++11 in C++14 you can use {1, 2, 3, 4, 5}
    std::array<int, 5> arr2;

    displayArr(arr1);
    displayArr(arr2);

    arr2 = { 10, 20, 30, 40, 50 };

    std::cout << "Size of Array 1 is : " << arr1.size() << std::endl;
    std::cout << "Size of Array 2 is : " << arr2.size() << std::endl;

    arr1[1] = 0;
    arr1.at(1) = 20;
    displayArr(arr1);

    std::cout << "Front of Array 2 is : " << arr2.front() << std::endl;
    std::cout << "Back of Array 2 is : " << arr2.back() << std::endl;
}

void arrFillAndSwap()
{
    std::cout << "\n=======================================" << std::endl;
    std::cout << "-----Array Fill and Swap Functions-----" << std::endl;

    std::array<int, 5> arr1{ {1, 2, 3, 4, 5} };
    std::array<int, 5> arr2{ {10, 20, 30, 40, 50} };

    displayArr(arr1);
    displayArr(arr2);
    std::cout << std::endl;

    arr1.fill(0);
    
    std::cout << "After the Fill Function." << std::endl;
    displayArr(arr1);
    displayArr(arr2);
    std::cout << std::endl;

    arr1.swap(arr2); 

    std::cout << "After the Swap Function." << std::endl;
    displayArr(arr1);
    displayArr(arr2);
}

void arrWithPointer()
{
    std::cout << "\n============================" << std::endl;
    std::cout << "-----Array With Pointer-----" << std::endl;

    std::array<int, 5> arr{ {1, 2, 3, 4, 5} };

    int* ptr = arr.data();
    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;
    *ptr = 11;

    displayArr(arr);
} 

void arrSortFunc()
{
    std::cout << "\n=============================" << std::endl;
    std::cout << "-----Array Sort Function-----" << std::endl;

    std::array<int, 5> arr{ {2, 4, 5, 3, 1} };
    
    std::cout << "Array before sorting." << std::endl;
    displayArr(arr);
    std::cout << "Array after sorting." << std::endl;
    std::sort(arr.begin(), arr.end());
    displayArr(arr);
}

void arrMinAndMax()
{
    std::cout << "\n====================================" << std::endl;
    std::cout << "-----Array Min and Max Elements-----" << std::endl;

    std::array<int, 5> arr{ {12, 54, 56, 32, 78} };

    std::array<int, 5>::iterator minNum = std::min_element(arr.begin(), arr.end());
    auto maxNum = std::max_element(arr.begin(), arr.end());
    std::cout << "Min : " << *minNum << " || Max : " << *maxNum << std::endl;
}

void arrAdjacentFind()
{
    std::cout << "\n======================================" << std::endl;
    std::cout << "-----Array Adjacent Find Function-----" << std::endl;
    
    std::array<int, 5> arr{ {2, 1, 3, 5, 5} };

    auto adjacent = std::adjacent_find(arr.begin(), arr.end());
    if (adjacent != arr.end())
    {
        std::cout << "Adjacent element found with value : " << *adjacent << std::endl;
    }
    else
    {
        std::cout << "No adjacent elemets found." << std::endl;
    }
}

void arrAccumulate()
{
    std::cout << "\n==========================" << std::endl;
    std::cout << "-----Array Accumulate-----" << std::endl;

    std::array<int, 5> arr{ {1, 2, 3, 4, 5} };

    int sum = std::accumulate(arr.begin(), arr.end(), 0);   // 0 means start from 0, if it will be 10 -> 10 + 1 + 2 + 3 + 4 + 5 = 25
    std::cout << "Sum of the elements in Array is : " << sum << std::endl;
}

void arrCount()
{
    std::cout << "\n==============================" << std::endl;
    std::cout << "-----Array Count Function-----" << std::endl;

    std::array<int, 10> arr{ {3, 2, 3, 4, 3, 1, 3, 2, 3, 1} };

    int count = std::count(arr.begin(), arr.end(), 3);
    std::cout << "This array includes 3 " << count << " times." << std::endl;
}