#include <iostream>
#include <cmath>
using namespace std;
int main() {
    cout << "- - - Immolate Improved! - - -" << endl;
    float orkHealth, orkMagicResistance, damage;
    do {
        cout << "Введите количество здоровья Орка: ";
        cin >> orkHealth;
        if (orkHealth<=0)cout<<"Только у мертвеца нет здоровья!\n";
        else if (orkHealth>1.f)cout<<"К сожалению, разработчики пожадничали и не дали возможности Орку иметь большее количество здоровья."<<endl;
    }while (orkHealth<=0||orkHealth>1.f);
    do {
        cout << "Сопротивление Орка к магии: ";
        cin >> orkMagicResistance;
        orkMagicResistance-=1.f;
        orkMagicResistance=abs(orkMagicResistance);
        if (orkMagicResistance<0)cout<<"Сопротивление магии не может быть отрицательным!\n";
        else if (orkMagicResistance>1.f)cout<<"Сопротивление не может превышать 100 процентов!\n";
    }while (orkMagicResistance<0||orkMagicResistance>1.f);

    do{
        do {
            cout << "Введите наносимый огненным шаром урон: ";
            cin >> damage;
            if (damage<0)cout<<"Вы не можете восстанавливать здоровье огненным шаром :)"<<endl;
            else if (damage>1.f)cout<<"Огненный шар не может нанести более 100% урона."<<endl;
        }while (damage<0||damage>1.f);
        float temporaryHealth=orkHealth;
        orkHealth-=damage*orkMagicResistance;
        cout<<"Итоговый урон от удара: "<<temporaryHealth-orkHealth<<endl;
        if (orkHealth<0)orkHealth=0;
        cout<<"Оставшиеся очки здоровья: "<<orkHealth<<endl;
        if (orkMagicResistance==0)cout<<"Магией этого орка не пробить! Используйте физический урон ;)";
    }while (orkHealth>0&&orkMagicResistance>0);
    return 0;
}
