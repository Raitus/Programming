#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int countOfOperations, inputNum;
    std::cin>>countOfOperations;
    std::cin.ignore(INTMAX_MAX,'\n');
    std::vector<bool> queue;
    std::string input, word, num;
    for (int i = 0; i < countOfOperations; ++i) {
        std::getline(std::cin, input);
        bool space{false};
        for (int j = 0; input[j]!='\0'; ++j) {
            if (input[j]==' ') {
                space=true;
            }else {
                if (!space) word += input[j];
                else {
                    num+=input[j];
                }
            }
        }
        if (space) inputNum = std::stoi(num);
        if (word == "COME"){
                for (int j = 0; j < std::abs(inputNum); ++j) {
                    if (inputNum>0){
                        queue.push_back(false);
                    }else{
                        queue.pop_back();
                    }
                }
        }else if (word == "WORRY"){
            queue[inputNum] = true;
        }else if (word == "QUIET"){
            queue[inputNum] = false;
        }else{
            std::cout << std::count(begin(queue), end(queue), true) << std::endl;
        }
        word = "";
        input = "";
        num = "";
    }
    return 0;
}
