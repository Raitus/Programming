#include <iostream>
#include <map>
#include <string>

void CharAnalyser(std::map<char, int>& vocabulary, const std::string& word){
    for (char i : word) {
        vocabulary[i]++;
    }
}

bool BuildCharCounters(std::map<char, int>& firstMap, std::map<char, int>& secondMap,
                       const std::string& firstWord, const std::string& secondWord){
    CharAnalyser(firstMap, firstWord);
    CharAnalyser(secondMap, secondWord);
    if (firstMap==secondMap){
        return true;
    }else{
        return false;
    }
}

int main() {
    std::map<char, int> firstWordCharCount, secondWordCharCount;
    int wordsNumber;
    std::cin>>wordsNumber;
    for (int i = 0; i < wordsNumber; ++i) {
        std::string firstWord, secondWord;
        std::cin>>firstWord>>secondWord;
        if (BuildCharCounters(firstWordCharCount, secondWordCharCount, firstWord, secondWord)){
            std::cout<<"true"<<std::endl;
        }else{
            std::cout<<"false"<<std::endl;
        }
        firstWordCharCount.clear();
        secondWordCharCount.clear();
    }
    return 0;
}
