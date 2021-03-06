#include <iostream>
#include <string>
#include <map>

int main() {
    int repeats;
    std::cin>>repeats;
    std::map<std::string, std::string> countryCapitalList;
    for (int i = 0; i < repeats; ++i) {
        std::string operation;
        std::cin>>operation;
        if (operation == "CHANGE_CAPITAL"){
            std::string country, newCapital;
            std::cin>>country>>newCapital;
            bool is_found{false};
            for (auto& item : countryCapitalList) {
                if (item.first==country){
                    if (item.second == newCapital){
                        std::cout<<"Country "<<country<<" hasn't changed its capital"<< std::endl;
                    }else{
                        std::cout<<"Country "<<country<<" has changed its capital from "
                            << item.second << " to " << newCapital << std::endl;
                        item.second = newCapital;
                    }
                    is_found = true;
                }
            }
            if (!is_found){
                std::cout<<"Introduce new country "<< country << " with capital "<< newCapital << std::endl;
                countryCapitalList[country] = newCapital;
            }
        }else if (operation == "RENAME"){
            std::string old_country_name, new_country_name;
            std::cin>>old_country_name>>new_country_name;
            if (countryCapitalList.empty()||old_country_name==new_country_name
                || countryCapitalList.count(new_country_name) == 1){
                std::cout << "Incorrect rename, skip" << std::endl;
            } else {
                countryCapitalList[new_country_name] = countryCapitalList[old_country_name];
                std::cout << "Country " << old_country_name << " with capital " << countryCapitalList[new_country_name]
                    << " has been renamed to " << new_country_name << std::endl;
                countryCapitalList.erase(old_country_name);
            }
        }else if (operation == "ABOUT"){
            std::string country;
            std::cin>>country;
            bool is_exist{false};
            for (const auto& item : countryCapitalList) {
                if (item.first==country){
                    std::cout<<"Country "<<item.first<<" has capital "<<item.second<<std::endl;
                    is_exist = true;
                    break;
                }
            }
            if (!is_exist){
                std::cout<<"Country "<<country<<" doesn't exist "<<std::endl;
            }
        }else if (operation == "DUMP"){
            if (countryCapitalList.empty()){
                std::cout<<"There are no countries in the world"<<std::endl;
            }else{
                for (const auto& item : countryCapitalList) {
                    std::cout << item.first << "/" << item.second << " ";
                }
                std::cout<<std::endl;
            }
        }
    }
    return 0;
}
