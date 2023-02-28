#include <iostream>
#include <map> 
#include <set>
#include <string>
// C++ have 4 type of maps 1-Map, 2-Unordered Map, 3-Multimap, 4-Unordered Multimap.
// Maps store their elements as key value pairs using the std::pair objects
// Maps doesn't have the concepts of front and back

template<typename T1, typename T2>
void displayMap(const std::map<T1, T2>& m)
{
    std::cout << "[ ";
    for (const auto &it : m)
    {
        std::cout << it.first << ":" << it.second << " ";
    }
    std::cout << "]" << std::endl;
}

void displayMap(const std::map<std::string, std::set<int>>& m)
{
    std::cout << "[ ";
    for (const auto& it : m)
    {
        std::cout << it.first << ":[ ";
        for (const auto& elem : it.second)
        {
            std::cout << elem << " ";
        }
        std::cout << "] ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::cout << "-----Basic Operations of Maps-----" << std::endl;
    std::map<std::string, int> m{ {"Larry", 16}, {"Moe", 25}, {"Curly", 48} };
    displayMap(m);

    m.insert(std::pair<std::string, int>("Anna", 10));
    displayMap(m);

    m.insert(std::make_pair("Joe", 56));
    displayMap(m);

    m["Frank"] = 18; // with this definition we can add pair to a map
    displayMap(m);

    m["Frank"] += 10;
    displayMap(m);

    m.erase("Frank");
    displayMap(m);

    std::cout << "Count for Joe : " << m.count("Joe") << std::endl;
    std::cout << "Count for Frank : " << m.count("Frank") << std::endl;

    auto it = m.find("Larry");
    if (it != m.end())
    {
        std::cout << "Found : " << it->first << ":" << it->second << std::endl;
    }

    m.clear();
    displayMap(m);

    std::cout << std::endl;
    std::cout << "-----Using Sets with Maps-----" << std::endl;
    std::map<std::string, std::set<int>> grades{ {"Larry", {90, 100}}, {"Moe",{94}}, {"Curly", {80, 90, 100}} };
    displayMap(grades);

    grades["Larry"].insert(95);
    displayMap(grades);

    auto grd = grades.find("Moe");
    if (grd != grades.end())
    {
        grd->second.insert(78);
    }
    displayMap(grades);

    return 0;

}
