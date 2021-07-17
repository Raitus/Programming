#include <iostream>
#include <cmath>

using namespace std;

int main() {
  cout << "\t- - - Игрушечная история - - -\n" << endl;
  float x, y, z;
  int cubeSet, cubes;
  cout << "Введите размеры бруска\nX: ";
  cin >> x;
  cout << "Y: ";
  cin >> y;
  cout << "Z: ";
  cin >> z;

  if (x < 5 || y < 5 || z < 5) {
	cout << "Не получится сделать ни одного идеального кубика.";
  } else {
	cubes = floor(y/5)*floor(z/5)*floor(x/5);

	int i = 0;
	do {
	  i++;
	  if (pow(i + 1, i + 1) > cubes) cubeSet = pow(i, i);
	} while (pow(i + 1, i + 1) <= cubes);

	cout << "Из этого бруска можно изготовить " << cubes;
	if (cubes%5==0 || (cubes%10 >= 6 && cubes%10 <= 9) || (cubes%100 >= 11 && cubes%100 <= 14)) {
	  cout << " кубиков." << endl;
	} else if (cubes%10 >= 2 && cubes%10 <= 4) {
	  cout << " кубика." << endl;
	} else cout << " кубик." << endl;

	cout << "Из них можно составить набор из " << cubeSet;
	if ((cubeSet%10 >= 2 && cubeSet%10 <= 9) || cubeSet%100 >= 11) {
	  cout << " кубиков." << endl;
	} else if (cubeSet%10==1)cout << " кубика." << endl;
  }
  return 0;
}
