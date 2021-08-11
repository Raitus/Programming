#include <iostream>

int main() {
  std::cout << "--- Banquet table ---\n" << std::endl;

  int plates[2][6] = {{3, 2, 2, 2, 2, 2},
					  {3, 2, 2, 2, 2, 2}};
  int tableware[2][6] = {{4, 3, 3, 3, 3, 3},
						 {4, 3, 3, 3, 3, 3}};
  int chairs[2][6] = {{1, 1, 1, 1, 1, 1},
					  {1, 1, 1, 1, 1, 1}};
  chairs[0][4]++; //added new chair for a child
  {
    tableware[1][2]--; //person at [1][2] place lost his spoon
    tableware[1][0]--; //VIP person take his spoon to the person at [1][2] place
    tableware[1][2]++; //person at [1][2] place took the spoon from VIP person
  }
  plates[1][0]--; //officiant take away desert plate
  return 0;
}
