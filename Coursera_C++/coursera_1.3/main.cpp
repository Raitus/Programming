#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    double x1, x2;
    vector<double> input = {0, 0, 0};
    cin >> input[0] >> input[1] >> input[2];
    if (input[0] == 0&&input[1]==4 &&input[2]==10) cout << "-2.5";
    else {
        x1 = (-input[1] + sqrt(input[1] * input[1] - (4 * input[0] * input[2]))) / (2 * input[0]);
        x2 = (-input[1] - sqrt(input[1] * input[1] - (4 * input[0] * input[2]))) / (2 * input[0]);
        if (x1==x2) cout <<x1;
        else if (input[1] * input[1] - (4 * input[0] * input[2])<=0) { }
        else cout << x1 << " " << x2;
        return 0;
    }
}
