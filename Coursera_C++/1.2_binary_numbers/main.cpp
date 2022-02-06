#include <iostream>
#include <vector>

int main() {
    int num;
    std::cin>>num;
    std::vector<bool> vec;
    if (num<=0) std::cout<<"0";
    else {
        do {
            if (num % 2 == 1) {
                vec.push_back(true);
                num /= 2;
            } else {
                vec.push_back(false);
                num /= 2;
            }
        } while (num != 0);
        bool check{false};
        do {
            if (vec.back()) {
                check = true;
                std::cout << "1";
            } else if (check)std::cout << "0";

            vec.pop_back();
        } while (!vec.empty());
    }
    return 0;
}
