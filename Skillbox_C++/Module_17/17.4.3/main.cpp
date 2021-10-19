#include <iostream>

int LengthOfString(const char *string){
  int charCount{0};
  for (; string[charCount]!='\0'; ++charCount) {}
  return charCount;
}

std::string Substr(const char *stringA, const char *stringB) {
  int stringA_Length, stringB_Length;
  stringA_Length = LengthOfString(stringA);
  stringB_Length = LengthOfString(stringB);
  bool endOfString{false};
  for (int i{0}; stringA_Length-i>=stringB_Length && !endOfString && stringA[i] != '\0'; ++i) {
    if (stringA[i] == *stringB) {
      bool compare{false};
      for (int j{0}; stringB[j] != '\0'; ++j) {
        if (stringA[i + j] == '\0') {
          endOfString = true;
          break;
        }else if (stringA[i + j] != stringB[j]) {
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
  char *a = "Hello world"; // first string
  char *b = "wor"; // true
  char *c = "banana"; //false
  char *d = "Hell"; //true
  char *e = "ld"; //true
  char *f = "o l"; //false
  char *g = "lo "; //true
  char *i = "llo worlk"; //false
  std::cout << Substr(a, b) << " " << Substr(a, c) << " " << Substr(a, d) << " " << Substr(a, e) << " " << Substr(a, f)
            << " " << Substr(a, g)<< " " << Substr(a, i);
  return 0;
}
