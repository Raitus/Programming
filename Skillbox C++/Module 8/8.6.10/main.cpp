#include <iostream>
#include <math.h>
using namespace std;
int main() {
  cout << "- - - Яйца - - -" << endl;
  float dangerousMax, D, x, from = 0.f, to = 4.f;
  do {
	cout << "Введите максимально допустимый уровень опасности: ";
	cin >> dangerousMax;
  } while (dangerousMax < 0);
	do {
	  x = to-(to-from)/2.f;
	  D = pow(x, 3) - (3*pow(x, 2)) - (12*x) + 10;
	  if (D>dangerousMax){
		from=x;
	  }else{
	    to=x;
	  }
	} while (fabs(D) > dangerousMax);
  cout << "Приблизительная глубина безопасной кладки: " << x << " метра.";
  return 0;
}
