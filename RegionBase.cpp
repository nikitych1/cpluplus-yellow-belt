#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <tuple>
#include <algorithm>

enum class Lang {
    DE, FR, IT
};

struct Region {
    std::string std_name;
    std::string parent_std_name;
    std::map<Lang, std::string> names;
    int64_t population;


};

bool operator< (const Region &lhs, const Region &rhs)
{
    return std::make_tuple(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population)
    < std::make_tuple(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const std::vector<Region>& regions)
{
    std::map<Region, uint32_t> dups;
    uint32_t dublicates = 0;

    for (auto& item : regions)
        dublicates = std::max(dublicates, ++dups[item]);

    return dublicates;
}

int main() {
    std::cout << FindMaxRepetitionCount({
       {
               "Moscow",
               "Russia",
               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
               89
       }, {
               "Russia",
               "Eurasia",
               {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
               89
       }, {
               "Moscow",
               "Russia",
               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
               89
       }, {
               "Moscow",
               "Russia",
               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
               89
       }, {
               "Russia",
               "Eurasia",
               {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
               89
       },
}) << std::endl;

    std::cout << FindMaxRepetitionCount({
       {
               "Moscow",
               "Russia",
               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
               89
       }, {
               "Russia",
               "Eurasia",
               {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
               89
       }, {
               "Moscow",
               "Russia",
               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
               89
       }, {
               "Moscow",
               "Toulouse",
               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
               89
       }, {
               "Moscow",
               "Russia",
               {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
               31
       },
    }) << std::endl;

    return 0;
}

