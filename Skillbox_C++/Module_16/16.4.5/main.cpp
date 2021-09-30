#include <iostream>
#include <sstream>

enum Electricity {
  ELECTRICITY_ALL_HOUSE = 1,
  ELECTRICITY_MAIN_SOCKETS,
  ELECTRICITY_INNER_LIGHT = 4,
  ELECTRICITY_OUTER_LIGHT = 8,
  ELECTRICITY_HOUSE_HEATING = 16,
  ELECTRICITY_WATER_PUMP_HEATING = 32,
  ELECTRICITY_CONDITIONER = 64
};

bool TemperatureCorrectnessCheck(std::string &value) {
  for (char i: value) {
    if (!(i >= '0' && i <= '9' || i == '.' || i == ',')) {
      return false;
    }
  }
  return true;
}

bool GlobalInputCorrectness(std::stringstream &input) {
  std::string value;
  input >> value;
  if (!TemperatureCorrectnessCheck(value)) return false;
  input >> value;
  if (!TemperatureCorrectnessCheck(value)) return false;
  input >> value;
  if (value != "yes" || value != "no") {
    for (char i: value) {
      if (!(i == 'y' || i == 'n')) {
        return false;
      }
    }
  }
  input >> value;
  if (value != "on" && value != "off") {
    return false;
  }
  return true;
}

void GlobalInput(std::stringstream &input, int time) {
  std::cout
      << "Input main characteristic of all sensors in order: output temperature, input temperature, movement, light."
      << std::endl
      << "Time: " << time << ":00"
      << std::endl;
  bool check;
  do {
    check = false;
    std::string inputCharacteristics;
    std::getline(std::cin, inputCharacteristics);
    input << inputCharacteristics;
    if (!GlobalInputCorrectness(input)) {
      std::cout << "Something incorrect. Try again!" << std::endl;
      check = true;
      input.str("");
    } else {
      input.str("");
      input.clear();
      input << inputCharacteristics;
    }
  } while (check);
}

void ConditionsRealisation(std::stringstream &input) {
  std::string outputTemperature, inputTemperature, movement, light;
  input >> outputTemperature;
  input >> inputTemperature;
  input >> movement;
  input >> light;

}

int main() {
  std::cout << "--- Clever house ---" << std::endl;
  std::stringstream input;
  int time{0};
  GlobalInput(input, time);
  ConditionsRealisation(input);

  return 0;
}
