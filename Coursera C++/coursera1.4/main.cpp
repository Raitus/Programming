#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a==0||b==0) cout << "Impossible";
    else cout << a/b;
    return 0;
}
