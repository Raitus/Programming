#include <iostream>
#include <set>
#include <string>
#include <map>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m) {
    std::set<std::string> data;
    for (auto& pair : m) {
        data.insert(pair.second);
    }
    return data;
}
