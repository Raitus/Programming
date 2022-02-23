#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int numCount;
    std::cin>>numCount;
    std::vector<int> numbers(numCount);
    for (int i = 0; i < numCount; ++i) {
        std::cin>>numbers[i];
    }
    std::sort(numbers.begin(), numbers.end(), [](auto& a, auto& b){return (std::abs(a)<std::abs(b));});
    for (const auto& item : numbers) {
        std::cout<<item<<" ";
    }
}
