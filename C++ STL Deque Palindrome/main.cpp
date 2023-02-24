#include <iostream>
#include <deque>
#include <iomanip>
#include <cctype>

bool isPalindrome(const std::string& str);

int main()
{   
    std::string name = "AbceCffceCba";

    std::cout << isPalindrome(name) << std::endl;

 	return 0;
}

bool isPalindrome(const std::string& str)
{
    std::deque<char> deq;
    for (auto it : str)
    {
        if (std::isalpha(it))
        {
            deq.push_back(std::toupper(it));
        }
    }

    char c1;
    char c2;

    while (deq.size() > 1)
    {
        c1 = deq.front();
        c2 = deq.back();
        deq.pop_back();
        deq.pop_front();
        if (c1 != c2)
        {
            return false;
        }

    }
    
    return true;
}