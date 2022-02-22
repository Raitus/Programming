#include <iostream>
#include <map>
#include <vector>

int main() {
    std::map<int, std::vector<std::string>> busList;
    int commandCount;
    std::cin >> commandCount;
    for (int i = 0; i < commandCount; ++i) {
        int stationCount;
        std::cin >> stationCount;
        std::vector<std::string> station(stationCount);
        for (int j = 0; j < stationCount; ++j) {
            std::cin >> station[j];
        }
        if (busList.empty()) {
            std::cout << "New bus 1" << std::endl;
            busList[1] = station;
        } else {
            for (auto &line: busList) {
                if (stationCount == line.second.size() && line.second == station) {
                        std::cout << "Already exists for " << line.first << std::endl;
                        break;
                } else if (line.first == busList.end()->first) {
                    int size{static_cast<int>(busList.size()) + 1};
                    std::cout << "New bus " << size << std::endl;
                    busList[size] = station;
                    break;
                }
            }
        }
    }
    return 0;
}
