#include <iostream>

int main() {
  std::cout << "--- World chunk visualisation ---" << std::endl;

  bool chunk[10][5][5];
  for (auto & i : chunk) {
	for (auto & j : i) {
	  for (bool & k : j) {
		k=true;
	  }
	}
  }

  for (int z = 0; z < 10; ++z) {
	for (int y = 0, x=0; y < 5; ++y, x=0) {
	  for ((z<5? x +=z:x=10-z); x < 5; ++x) {
		chunk[z][y][x]=false;
	  }
	}
  }

  for (int z = 0; z < 10; ++z) {
	for (int y = 0; y < 5; ++y) {
	  for (int x = 0; x < 5; ++x) {
		std::cout<<chunk[z][y][x]<<" ";
	  }
	  if (y==2) std::cout<<"\t"<<z+1;
	  std::cout<<std::endl;
	}
	std::cout<<std::endl;
  }

  {
    int cZ;
    bool check;
	do {
	  check=false;
	  std::cout << "Choose chunk level which do you want to see closer: ";
	  std::cin >> cZ;
	  if (cZ<1||cZ>10){
	    std::cout<<"\tIncorrect entered number. Try again!\n";
	    check=true;
	  }
	}while(check);
    for (int y = 0; y < 5; ++y) {
      for (int x = 0; x < 5; ++x) {
        std::cout<<chunk[cZ-1][y][x]<<" ";

      }
      if (y==2) std::cout<<"\t"<<cZ;
      std::cout<<std::endl;
    }
  }

  return 0;
}
