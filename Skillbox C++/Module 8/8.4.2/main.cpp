#include <iostream>
#include <cmath>
using namespace std;
int main() {
    std::cout << "Введите угол в градусах: " << std::endl;
    float angle, PI=3.14159;
    cin>>angle;
    angle=fabs(angle);
    angle/=360;
    angle=(float)angle-(int)angle;
    angle*=360;
    angle/=57.296;
    angle=round(angle*100000)/100000;


    cout<<angle<<endl;
    if(angle>0.08917&&angle<6.19401) cout<<"Угол небезопасен!\n";
    else cout<<"Угол безопасен!\n";
    return 0;
}
