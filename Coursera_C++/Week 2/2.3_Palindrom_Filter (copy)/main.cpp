#include <iostream>
#include <vector>
#include <string>

bool IsPalindrom(std::string word){
    for (int i = 0; i < word.length()/2; ++i) {
        if (word[i]!=word[word.length()-i-1]){
            return false;
        }
    }
    return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string>& initialString, int minLength){
    std::vector<std::string> palindroms;
    for (auto & i : initialString) {
        if (i.length() >= minLength && IsPalindrom(i)) {
            palindroms.push_back(i);
        }
    }
    return palindroms;
}

int main() {
    std::cout << "--- Palindrom filter ---" << std::endl;
    std::vector<std::string> words{"abacaba", "aba"}, result;
    int minLength{2};
    result = PalindromFilter(words, minLength);
    for (auto& i:result) {
        if (i == result.back()) std::cout<<i;
        else std::cout<<i<<", ";
    }
    return 0;
}
