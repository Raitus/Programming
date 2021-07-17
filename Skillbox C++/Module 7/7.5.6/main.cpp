#include <iostream>
using namespace std;
int main() {
    int x, y;
    cout<< "Введите ширину рамки: ";
    cin>>x;
    cout<< "Введите высоту рамки: ";
    cin>>y;
    for (int i=1;i<=y;i++){
        for (int j=1; j<=x;j++){
            if (j==1||j==x) cout<<"|";
            else if (j>1&&j<x&&(i==1||i==y)) cout<<"-";
            else cout<<" ";
        }
        cout<<"\n";
    }
}