#include <iostream>
using namespace std;
int main() {
    int a,b,i;
    cin>>a>>b;
    i=a;
    while (i<=b){
        if (i%2==0) cout << i <<" ";
        ++i;
    }

    return 0;
}
