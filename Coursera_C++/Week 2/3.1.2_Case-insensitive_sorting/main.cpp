#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int inputCount;
    std::cin>>inputCount;
    std::vector<std::string> list (inputCount);
    for (int i = 0; i < inputCount; ++i) {
        std::cin>>list[i];
    }
    std::sort(list.begin(), list.end(), [](const std::string& word1, const std::string& word2){
        std::vector<std::string> words {word1, word2};
        for (auto& word : words) {
            for (auto& symbol : word) {
                symbol = static_cast<char>(tolower(symbol));
            }
        }
        return (words[0]<words[1]);
    });
    for (const auto& word : list) {
        std::cout<<word<<" ";
    }
}
