/*#include <iostream>

using namespace std;

int main() {
    int numerator, denominator, temporaryDenominator = 1, result;
    cin >> numerator >> denominator;
    if (numerator == 0 || denominator == 0) std::cout << "Impossible";
    else {
        while (temporaryDenominator <= denominator || temporaryDenominator <= numerator) {
            if (numerator % temporaryDenominator == 0 && denominator % temporaryDenominator == 0)
                result = temporaryDenominator;
            temporaryDenominator++;
        }
        cout << result;
    }
    return 0;
}*/

#include <iostream>

using namespace std;

int main() {
    int numerator, denominator, temporaryDenominator = 1, result;
    cin >> numerator >> denominator;

        if (0 < denominator && 0 < numerator) {
            if (numerator > denominator) { result = numerator % denominator;
            }
            else { result = denominator % numerator;
            }


        }
        if (result == 0) cout << result;
        else cout << 1;

    }
    return 0;
}