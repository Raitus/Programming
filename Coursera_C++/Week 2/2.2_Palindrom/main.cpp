#include <iostream>
#include <string>

bool IsPalindrom(std::string word){
    for (int i = 0; i < word.length()/2; ++i) {
        if (word[i]!=word[word.length()-i-1]){
            return false;
        }
    }
    return true;
}

int main() {
    std::string str;
    std::getline(std::cin,str);
    if (IsPalindrom(str)) std::cout<<"true";
    else std::cout<<"false";
    return 0;
}
