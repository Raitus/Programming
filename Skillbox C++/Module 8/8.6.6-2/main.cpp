#include <iostream>

int main() {
  int x = 0.001f*1.496f*pow(10, 11) - 9, y = 0;
  char key;
  std::cout << "\t- - - Красный Марс 2.0 - - -\n";
  while (true) {
	std::cout << "[Программа]: Марсоход находится на позиции " << x;
	std::cout << ", " << y << ", введите команду:\n[Оператор]: ";
	std::cin >> key;

	if (key=='A') {
	  x -= 1;
	} else if (key=='W') {
	  y += 1;
	} else if (key=='S') {
	  y -= 1;
	} else if (key=='D') {
	  x += 1;
	}
  }
}