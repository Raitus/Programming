#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> a = {"", "", ""};
    cin >> a[0] >> a[1] >> a[2];
    if (a[0] <= a[1] && a[0] <= a[2]) {
        cout << a[0];
    } else if (a[1] <= a[0] && a[1] <= a[2]) {
        cout << a[1];
    } else if (a[2] <= a[1] && a[2] <= a[0]) {
        cout << a[2];
    }
    return 0;
}
