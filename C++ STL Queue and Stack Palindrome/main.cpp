#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cctype>
#include <iomanip>

std::string clearString(std::string str);
bool isPalindrome(std::string str);

int main()
{
	std::vector<std::string> testStrings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
		"avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
		"A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

	std::cout << std::boolalpha;
	std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
	for (const auto& s : testStrings) {
		std::cout << std::setw(8) << std::left << isPalindrome(s) << s << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

bool isPalindrome(std::string str)
{
	str = clearString(str);
	std::queue<char> q;
	std::stack<char> s;

	for (auto it : str)
	{
		q.push(it);
	}

	for (auto it : str)
	{
		s.push(it);
	}

	char a{};
	char b{};

	while (q.size() > 1)
	{
		a = q.front();
		b = s.top();
		q.pop();
		s.pop();
		if (a != b)
		{
			return false;
		}
	}
	return true;
}

std::string clearString(std::string str)
{
	std::string result{};
	for (auto it : str)
	{
		if (isalpha(it))
		{
			it = toupper(it);
			result += it;
		}
	}
	return result;
}
