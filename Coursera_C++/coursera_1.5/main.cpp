#include <iostream>
using namespace std;

int main() {
    double result;
    double N, A, B, X, Y;
    cin>>N>>A>>B>>X>>Y;
    if (N>B){
        cout << (N-=N*(Y/100)) << endl;
    }else if (N>A){
        cout << (N-=N*(X/100)) << endl;
    }else cout << N << endl;

    return 0;
}
