#include <iostream>
#include <string>
#include <map>
#include <vector>

int main() {
    int countOfCommands;
    std::cin>>countOfCommands;
    std::map<std::string, std::vector<std::string>> bus_routes;
    std::vector<std::string> bus_order;
    for (int i = 0; i < countOfCommands; ++i) {
        std::string command;
        std::cin>>command;
        if (command == "NEW_BUS"){
            std::string bus, stop;
            int stop_count;
            std::cin>>bus>>stop_count;
            bus_order.push_back(bus);
            for (int j = 0; j < stop_count; ++j) {
                std::cin>>stop;
                bus_routes[bus].push_back(stop);
            }
        }else if (command == "BUSES_FOR_STOP"){
            std::string stop;
            std::cin>>stop;
            bool is_exist{false};
            for (const auto& busOrder : bus_order) {
                const auto& busRoute = bus_routes[busOrder];
                for (const auto& j : busRoute) {
                    if (j == stop){
                        std::cout << busOrder << " ";
                        is_exist = true;
                        break;
                    }
                }
            }
            if (!is_exist) std::cout<<"No stop"<<std::endl;
            else std::cout<<std::endl;
        }else if (command == "STOPS_FOR_BUS"){
            std::string bus;
            std::cin>> bus;
            if (bus_routes.find(bus) == bus_routes.end()){
                std::cout<<"No bus"<<std::endl;
            } else {
                const auto& busRoute = bus_routes.find(bus);
                for (const auto& station : busRoute->second) {
                    std::cout<<"Stop "<<station<<":";
                    bool is_exist{false};
                    for (const auto& busOrder : bus_order) {
                        if (busOrder!=bus){
                            const auto& busRoute2 = bus_routes.find(busOrder);
                            for (const auto &item: busRoute2->second) {
                                if (item == station) {
                                    std::cout << " " << busRoute2->first;
                                    is_exist = true;
                                }
                            }
                        }
                    }
                    if (!is_exist) std::cout<<" no interchange";
                    std::cout << std::endl;
                }
            }
        }else if (command == "ALL_BUSES"){
            if (bus_order.empty()){
                std::cout<<"No buses"<<std::endl;
            }else {
                for (const auto& busRoute : bus_routes) {
                    std::cout << "Bus " << busRoute.first << ":";
                    for (const auto &station : busRoute.second) {
                        std::cout << " " << station;
                    }
                    std::cout << std::endl;
                }
            }
        } else {
            std::cout<<"ERROR!"<<std::endl;
        }

    }
    return 0;
}
