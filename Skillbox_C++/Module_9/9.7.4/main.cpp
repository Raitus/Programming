#include <iostream>
#include "string"

int main() {
  std::string str;
  std::cout << "Input string: " << std::endl;
  std::getline(std::cin, str);
  int count = 0;
  for (int i = 0;i < str.length(); i++) {
	if ((i < str.length() && i!=0 && str[i]!=' ' && str[i - 1]==' ')
		|| (i < str.length() && i==0 && str[i]!=' ')) {
	  count++;
	}
  }
  std::cout << "Result: " << count;
  return 0;
}
