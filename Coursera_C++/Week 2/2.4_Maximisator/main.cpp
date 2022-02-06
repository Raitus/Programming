#include <iostream>

void UpdateIfGreater(int first, int& second){
    if (first > second){
        int tmp = first;
        first = second;
        second = tmp;
    }
}

int main() {
    int a = 4;
    int b = 2;
    UpdateIfGreater(a, b);
    return 0;
}
