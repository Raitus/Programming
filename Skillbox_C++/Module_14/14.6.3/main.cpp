#include <iostream>

int main() {
  std::cout << "--- Snake way ---\n" << std::endl;
  const int x{5}, y{5};
  int array[x][y];

  for (int j=0, number = 0; number < y*x; ++number, ++j) {
    array[j%x][j/x]=number+(((x-1)-2*(j%x))*(j/x%2));
    std::cout<<array[j%x][j/x]<<' ';

    if (j%x==4)std::cout<<std::endl; //"if" is used to transfer to a new line, we don`t need to use the second cycle

	/*for (int i = 4; i >=-4; i-=2, ++number, ++j) {
	  array[j%x][j/x]=number+(i*(j/x%2));
	  std::cout<<array[j%x][j/x]<<' ';
	}*/
  }


  return 0;
}
