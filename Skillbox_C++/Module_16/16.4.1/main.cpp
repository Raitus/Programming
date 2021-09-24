#include <iostream>
#include <cstdio>

void speedCheck (float &speed){
  if (speed>150.01){
    speed=150.0;
  }else if (speed<0){
    speed=0.0;
  }
}

int main() {
  std::cout << "--- Speedometer ---" << std::endl;
  float speed{0}, delta;
  char text[100];
  do {
    std::cout<<"Input delta: ";
    std::cin>>delta;
    speed+=delta;
    speedCheck(speed);
    std::sprintf(text,"Speed: %.1fkm/h",speed);
    std::cout<<text<<std::endl;
  }while(speed!=0);
  return 0;
}
