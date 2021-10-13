#include <iostream>

std::string Substr(const char *stringA, const char *stringB) {
  for (; *stringA != '\0'; ++stringA) {
    if (*stringA == *stringB) {
      bool compare{false};
      for (int i{0}; *stringA != '\0' && stringB[i] != '\0'; ++stringA, ++i) {
        if (*stringA != stringB[i]) {
          compare = false;
          break;
        } else compare = true;
      }
      if (compare) return "true";
    }
  }
  return "false";
}

int main() {
  std::cout << "--- M17 Exercise 3 ---" << std::endl;
  char *a = "Hello world";
  char *b = "wor";
  char *c = "banana";
  char *d = "Hell";
  char *e = "ld";
  char *f = "o l";
  std::cout << Substr(a, b) << " " << Substr(a, c) << " " << Substr(a, d) << " " << Substr(a, e) << " " << Substr(a, f);
  return 0;
}
