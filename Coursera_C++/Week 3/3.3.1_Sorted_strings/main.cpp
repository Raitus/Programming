#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SortedStrings {
public:
    void AddString(const std::string& s) {
        // добавить строку s в набор
        vec.push_back(s);
    }
    std::vector<std::string> GetSortedStrings() {
        // получить набор из всех добавленных строк в отсортированном порядке
        std::sort(vec.begin(), vec.end());
        return vec;
    }
private:
    std::vector<std::string> vec;
};
