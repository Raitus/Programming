#include <iostream>
#include "vector"

float BasketSum(std::vector<float> cost, std::vector<int> thingID) {
  float sum = 0;
  for (int i = 0; i < thingID.size(); ++i) {
	sum += cost[thingID[i]];
  }
  return sum;
}

int main() {
  std::cout << "--- Basket in the shop ---\n" << std::endl;
  std::vector<float> costs = {2.5, 4.25, 3.0, 10.0};
  std::vector<int> basket = {1, 1, 0, 3, 2, 2, 0};
  std::cout << "Total amount of things: " << BasketSum(costs, basket);
  return 0;
}
