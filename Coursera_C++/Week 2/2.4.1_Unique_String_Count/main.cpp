#include <iostream>
#include <set>
#include <string>

int main() {
    int operationCount;
    std::cin >> operationCount;
    std::set<std::string> values;
    for (int i = 0; i < operationCount; ++i) {
        std::string input;
        std::cin>>input;
        values.insert(input);
    }
    std::cout<<values.size();
    return 0;
}
