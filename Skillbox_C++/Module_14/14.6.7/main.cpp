#include <iostream>
#include "array"

void PopRegion(std::array<std::array<bool, 12>, 12> &pupyrka, int &count) {
  std::cout << "Choose region to make a Pop!\n";
int x1, x2, y1, y2;
bool check;
  do {
    check=false;
    std::cout<<"Input first coordinate in format x >> y: ";
    std::cin>>x1>>y1;
    if (x1<1||x1>12||y1<1||y1>12) {
      std::cout<<"You made mistake. Try again!\n";
      check=true;
    }
  }while(check);
  do {
    check=false;
    std::cout<<"Input second coordinate in format x >> y: ";
    std::cin>>x2>>y2;
    if (x2<1||x2>12||y2<1||y2>12) {
      std::cout<<"You made mistake. Try again!\n";
      check=true;
    }
  }while(check);
  for (int i = y1-1, popCount{0}; i <= y2-1; ++i) {
	for (int j = x1-1; j <= x2-1; ++j) {
	  if (pupyrka[i][j]){
		popCount++;
	    std::cout<<"Pop! ";
	    count--;
	    pupyrka[i][j]=false;
	    if (popCount%12==0) std::cout<<std::endl;
	  }
	}
  }

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
