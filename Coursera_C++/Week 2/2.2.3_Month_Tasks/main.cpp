#include <iostream>
#include <vector>

int main() {
    int countOfCommands, month{0};
    std::cin>>countOfCommands;
    std::vector<int> daysOfMonth{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::vector<std::vector<std::string>> eventNames(daysOfMonth[month]);
    for (int i = 0; i < countOfCommands; ++i) {
        int day;
        std::string operation_code;
        std::cin>>operation_code;
        if (operation_code=="ADD"){
            std::cin>>day;
            std::string event;
            std::cin>>event;
            eventNames[day-1].push_back(event);
        }else if (operation_code == "DUMP"){
            std::cin>>day;
            std::cout<<eventNames[day-1].size()<<" ";
            for (int j = 0; j < eventNames[day-1].size(); ++j) {
                if (j == eventNames[day-1].size()-1){
                    std::cout << eventNames[day-1][j];
                }else{
                    std::cout << eventNames[day-1][j]<<" ";
                }
            }
            std::cout<<std::endl;
        }else{
            if (month==11) month=0;
            else month++;
            if (daysOfMonth[month] >= (month==0 ? daysOfMonth[month] : daysOfMonth[month-1])){
                eventNames.resize(daysOfMonth[month]);
            }else{
                for (int j = daysOfMonth[month]; j < daysOfMonth[month-1]; ++j) {
                    for (int k = 0; k < eventNames[j].size(); ++k) {
                        eventNames[daysOfMonth[month]-1].push_back(eventNames[j][k]);
                    }
                }
                eventNames.resize(daysOfMonth[month]);
            }
        }
    }
    return 0;
}
