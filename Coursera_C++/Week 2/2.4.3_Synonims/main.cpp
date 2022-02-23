#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    int operationCount;
    std::cin>>operationCount;
    std::map<std::string, std::set<std::string>> dictionary;
    for (int i = 0; i < operationCount; ++i) {
        std::string command;
        std::cin>>command;
        if (command == "ADD"){
            std::string word1, word2;
            std::cin>>word1>>word2;
            dictionary[word1];
            dictionary.find(word1)->second.insert(word2);
            dictionary[word2];
            dictionary.find(word2)->second.insert(word1);
        }else if (command == "COUNT"){
            std::string input;
            std::cin>>input;
            if (dictionary.find(input)!=dictionary.end()){
                std::cout<<dictionary.find(input)->second.size()<<std::endl;
            }else{
                std::cout<<"0"<<std::endl;
            }
        }else if (command == "CHECK"){
            std::string word1, word2;
            std::cin>>word1>>word2;
            if (dictionary.find(word1)!=dictionary.end()){
                bool check{false};
                for (auto& item : dictionary[word1]) {
                    if (item == word2){
                        std::cout<<"YES"<<std::endl;
                        check = true;
                        break;
                    }
                }
                if (!check) std::cout<<"NO"<<std::endl;
            }else{
                std::cout<<"NO"<<std::endl;
            }
        }
    }
}
