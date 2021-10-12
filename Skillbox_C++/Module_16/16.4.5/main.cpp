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
    if (!(i >= '0' && i <= '9' || i == '.' || i == ',' || i == '-')) {
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
  if (value != "yes" && value != "no") {
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

void PrepareToRealisation(std::stringstream &input,
                          float &outTempFloat,
                          float &innerTempFloat,
                          std::string &movement,
                          std::string &light) {
  {
    std::string outputTemperature, inputTemperature;
    input >> outputTemperature;
    input >> inputTemperature;
    input >> movement;
    input >> light;
    outTempFloat = std::stof(outputTemperature);
    innerTempFloat = std::stof(inputTemperature);
  }
  if (movement == "y") {
    movement = "yes";
  } else if (movement == "n") movement = "no";
}

void ConditionsRealisation(std::stringstream &input,
                           int time,
                           int &status) {
  float outTempFloat, innerTempFloat;
  std::string movement, light;
  PrepareToRealisation(input, outTempFloat, innerTempFloat, movement, light);

  status |= ELECTRICITY_ALL_HOUSE;
  status |= ELECTRICITY_MAIN_SOCKETS;

  if (!((status & ELECTRICITY_ALL_HOUSE) && (status & ELECTRICITY_MAIN_SOCKETS))) {
    std::cout << "Electricity in house is off. Nothing happened!" << std::endl;
  } else {
    if (outTempFloat < 0.0 && !(status & ELECTRICITY_WATER_PUMP_HEATING)) {
      status |= ELECTRICITY_WATER_PUMP_HEATING;
      std::cout << "Water pump heating is on." << std::endl;
    } else if (outTempFloat > 5.0 && (status & ELECTRICITY_WATER_PUMP_HEATING)) {
      status &= ~ELECTRICITY_WATER_PUMP_HEATING;
      std::cout << "Water pump heating is off." << std::endl;
    }
    if (movement == "yes" && (time >= 16 && time <= 23 || time >= 0 && time <= 5)
        && !(status & ELECTRICITY_OUTER_LIGHT)) {
      status |= ELECTRICITY_OUTER_LIGHT;
      std::cout << "Outer light is on." << std::endl;
    } else if ((movement == "no" && status & ELECTRICITY_OUTER_LIGHT)
        || (movement == "yes" && time >= 5 && time <= 16 && status & ELECTRICITY_OUTER_LIGHT)) {
      status &= ~ELECTRICITY_OUTER_LIGHT;
      std::cout << "Outer light is off." << std::endl;
    }
    if (innerTempFloat < 22.0 && !(status & ELECTRICITY_HOUSE_HEATING)) {
      status |= ELECTRICITY_HOUSE_HEATING;
      std::cout << "Inner heating is on." << std::endl;
    } else if (innerTempFloat > 25.0 && (status & ELECTRICITY_HOUSE_HEATING)) {
      status &= ~ELECTRICITY_HOUSE_HEATING;
      std::cout << "Inner heating is off." << std::endl;
    }
    if (innerTempFloat > 30.0 && !(status & ELECTRICITY_CONDITIONER)) {
      status |= ELECTRICITY_CONDITIONER;
      std::cout << "Conditioner is on." << std::endl;
    } else if (innerTempFloat < 25 && (status & ELECTRICITY_CONDITIONER)) {
      status &= ~ELECTRICITY_CONDITIONER;
      std::cout << "Conditioner is off." << std::endl;
    }
    if (light == "on" && !(status & ELECTRICITY_INNER_LIGHT)) {
      status |= ELECTRICITY_INNER_LIGHT;
      int lightTemp = 2700;
      if (time >= 0 && time <= 16) {
        lightTemp = 5000;
      } else if (time > 16 && time <= 20) {
        lightTemp = 5000 - (20 - time%16)*575;
      }
      std::cout << "Inner light is on with temperature " << lightTemp << "K." << std::endl;
    } else if (light == "on" && ((time > 16 && time <= 23) || time == 0)) {
      int lightTemp = 2700;
      if (time > 16 && time <= 20) {
        lightTemp = 5000 - (time%16)*575;
      }
      std::cout << "Inner light is on with changed temperature to " << lightTemp << "K." << std::endl;
    } else if (light == "off" && status & ELECTRICITY_INNER_LIGHT) {
      status &= ~ELECTRICITY_INNER_LIGHT;
      std::cout << "Inner light is off." << std::endl;
    }
  }
  input.str("");
  input.clear();
}

int main() {
  std::cout << "--- Clever house ---" << std::endl;
  std::stringstream input;
  for (int time{0}, i{0}, status{0}; i < 48; ++i, ++time) {
    if (time == 24) time = 0;
    GlobalInput(input, time);
    ConditionsRealisation(input, time, status);
  }

  return 0;
}
