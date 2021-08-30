#include <iostream>
#include "array"

void Popping(std::array<std::array<bool, 12>, 12> &pupyrka, int &count, int &x1, int &y1, int &x2, int &y2){
  for (int i = y1-1; i <= y2-1; ++i) {
    for (int j = x1-1; j <= x2-1; ++j) {
      if (pupyrka[i][j]){
        std::cout<<"Pop! ";
        count--;
        pupyrka[i][j]=false;
      }else{
        std::cout<<"     ";
      }
    }
    std::cout << std::endl;
  }
}

bool CoordinatesCorrectness(int &x, int &y){
  if (x<1||x>12||y<1||y>12) {
    std::cout<<"You made mistake. Try again!\n";
    return false;
  }
  return true;
}

void PopRegion(std::array<std::array<bool, 12>, 12> &pupyrka, int &count) {
  std::cout << "Choose region to make a Pop!\n";
int x1, x2, y1, y2;
  do {
    std::cout<<"Input first coordinate in format x >> y: ";
    std::cin>>x1>>y1;
  }while(!CoordinatesCorrectness(x1, y1));
  do {
    std::cout<<"Input second coordinate in format x >> y: ";
    std::cin>>x2>>y2;
  }while(!CoordinatesCorrectness(x2, y2));

  if (y1<y2){
    if (x1>=x2){
      std::swap(x1,x2);
    }
  }else{
    if (x1<x2){
      std::swap(y1,y2);
    }else{
      std::swap(x1,x2);
      std::swap(y1,y2);
    }
  }
  Popping(pupyrka, count, x1, y1, x2, y2);
}

void ArrayPrint(std::array<std::array<bool, 12>, 12> &pupyrka) {
  for (int i = 0; i < 13; ++i) {
	std::cout << i << "\t";
	for (int j = 0; j < 12; ++j) {
	  if (i==0) {
		std::cout << j + 1 << "\t";
	  } else {
		std::cout << pupyrka[i - 1][j] << "\t";
	  }
	}
	std::cout << std::endl;
  }
}

int main() {
  std::cout << "--- Pupyrka ---\n" << std::endl;

  std::array<std::array<bool, 12>, 12> pupyrka{};

  pupyrka.fill({true, true, true, true, true, true,
				true, true, true, true, true, true});
  int count{12*12};
  do {
    ArrayPrint(pupyrka);
    PopRegion(pupyrka, count);
  }while(count!=0);
  return 0;
}
