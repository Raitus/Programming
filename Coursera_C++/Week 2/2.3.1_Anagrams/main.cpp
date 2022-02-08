#include <iostream>
#include <map>
#include <string>

void CharAnalyser(std::map<char, int>& vocabulary, const std::string& word){
    for (char i : word) {
        vocabulary[i]++;
    }
}

std::map<char, int> BuildCharCounters(const std::string& word){
    std::map<char, int> vocabulary;
    CharAnalyser(vocabulary, word);
    return vocabulary;
}

int main() {
    int wordsNumber;
    std::cin>>wordsNumber;
    for (int i = 0; i < wordsNumber; ++i) {
        std::string firstWord, secondWord;
        std::cin>>firstWord>>secondWord;
        if (BuildCharCounters(firstWord)==
            BuildCharCounters(secondWord)){
            std::cout<<"YES"<<std::endl;
        }else{
            std::cout<<"NO"<<std::endl;
        }
    }
    return 0;
}
