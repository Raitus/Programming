#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    int operationCount;
    std::cin >> operationCount;
    std::vector<std::set<std::string>> busLines;
    for (int i = 0; i < operationCount; ++i) {
        int busStations;
        std::cin >> busStations;
        std::set<std::string> stations;
        for (int j = 0; j < busStations; ++j) {
            std::string word;
            std::cin >> word;
            stations.insert(word);
        }
        bool check{false};
        for (int j{0}; j < busLines.size(); j++) {
            if (busLines[j] == stations) {
                std::cout << "Already exists for " << j+1 << std::endl;
                check = true;
                break;
            }
        }
        if (!check) {
            std::cout << "New bus " << busLines.size() + 1 << std::endl;
            busLines.push_back(stations);
        }
    }
}
