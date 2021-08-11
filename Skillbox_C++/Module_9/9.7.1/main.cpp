#include <iostream>

int main() {
  std::cout << "Input the time in HH:MM format." << std::endl;
  std::string startTime, arrivingTime;
  int startHours, startMinutes, arrivingHours, arrivingMinutes;
  {
	bool check = false;
	do {
	  std::cout << "Input start time: ";
	  std::cin >> startTime;

	  if (startTime.length()!=5 || startTime[0] < '0' || startTime[0] > '9' || startTime[1] < '0' || startTime[1] > '9'
		  || startTime[2]!=':' || startTime[3] < '0' || startTime[3] > '9' || startTime[4] < '0'
		  || startTime[4] > '9') {
		std::cout << "Error! Please, input correct time at the time format HH:MM.\n";
	  } else {
		startHours = 10*(startTime[0] - '0') + (startTime[1] - '0');
		startMinutes = 10*(startTime[3] - '0') + (startTime[4] - '0');
		if (startHours > 24 || startHours < 0 || startMinutes > 59 || startMinutes < 0) {
		  std::cout << "Error! Please, input correct time at the time format HH:MM.\n";
		} else {
		  check = true;
		}
	  }
	} while (check==false);
	check = false;
	do {
	  std::cout << "Input arrival time: ";
	  std::cin >> arrivingTime;
	  if (arrivingTime.length()!=5 || arrivingTime[0] < '0' || arrivingTime[0] > '9' || arrivingTime[1] < '0'
		  || arrivingTime[1] > '9' || arrivingTime[2]!=':' || arrivingTime[3] < '0' || arrivingTime[3] > '9'
		  || arrivingTime[4] < '0' || arrivingTime[4] > '9') {
		std::cout << "Error! Please, input correct time at the time format HH:MM.\n";
	  } else {
		arrivingHours = 10*(arrivingTime[0] - '0') + (arrivingTime[1] - '0');
		arrivingMinutes = 10*(arrivingTime[3] - '0') + (arrivingTime[4] - '0');
		if (arrivingHours > 24 || arrivingHours < 0 || arrivingMinutes > 59 || arrivingMinutes < 0) {
		  std::cout << "Error! Please, input correct time at the time format HH:MM.\n";
		} else {
		  check = true;
		}
	  }
	} while (check==false);
  }

  std::cout << "You will be in the way ";
  int initialMinutes = startHours*60 + startMinutes;
  int eventualMinutes = arrivingHours*60 + arrivingMinutes;
  if (initialMinutes <= eventualMinutes) {
	int hours = (eventualMinutes - initialMinutes)/60;
	int minutes = (eventualMinutes - initialMinutes) - hours*60;
	std::cout << hours << " hours and " << minutes << " minutes.";
  } else {
	int hours = (1440 - initialMinutes + eventualMinutes)/60; // 1440 = 24*60
	int minutes = (1440 - initialMinutes + eventualMinutes) - hours*60;
	std::cout << hours << " hours and " << minutes << " minutes.";
  }
  return 0;
}
