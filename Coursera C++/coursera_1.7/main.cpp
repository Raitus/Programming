#include <iostream>
#include <string>
using namespace std;
int main() {
    string word;
    int index=0, countNumbersOfF=0, indexNumber;
    cin>>word;
    while(index!=word.size()&&countNumbersOfF!=2){
        if(word[index]=='f'){
            indexNumber=index;
            countNumbersOfF++;
        }
        ++index;
    }
    if (countNumbersOfF==0) cout<<-2;
    else if (countNumbersOfF==1) cout<<-1;
    else cout<< indexNumber;
    return 0;
}
