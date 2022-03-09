#include <iostream>
#include <map>

class Person {
public:
    void ChangeFirstName(int year, const std::string &first_name) {
        names[year] = first_name;
    }

    void ChangeLastName(int year, const std::string &last_name) {
        sernames[year] = last_name;
    }

    std::string GetFullName(int year) {
        std::string output;
        std::pair<int, std::string> concreteName{0, ""}, concreteSername{0, ""};
        for (auto &name: names) {
            if (name.first <= year) {
                concreteName = name;
            }
        }
        for (auto &sername: sernames) {
            if (sername.first <= year) {
                concreteSername = sername;
            }
        }
        if (concreteName.first == 0 && concreteSername.first == 0) {
            return "Incognito";
        } else if (concreteSername.first == 0) {
            return concreteName.second + " with unknown last name";
        } else if (concreteName.first == 0) {
            return concreteSername.second + " with unknown first name";
        } else {
            return concreteName.second + " " + concreteSername.second;
        }
    }

    std::string GetFullNameWithHistory(int year) {
        // получить все имена и фамилии по состоянию на конец года year

    }

private:
    std::map<int, std::string> names, sernames;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    std::cout << person.GetFullNameWithHistory(1990) << std::endl;

    person.ChangeFirstName(1966, "Pauline");
    std::cout << person.GetFullNameWithHistory(1966) << std::endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    std::cout << person.GetFullNameWithHistory(1967) << std::endl;

    return 0;
}