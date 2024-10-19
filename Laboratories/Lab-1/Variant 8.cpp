/*
    Вариант 8
    Угол задан в радианах. Найти его величину в градусах, минутах и секундах.
*/

#include <iostream>

using namespace std;

int main() {
    double alpha;
    cin >> alpha;
    double beta = alpha / numbers::pi * 180;
    cout << beta << " <-- degrees" << endl;
    cout << beta * 60 << " <-- minutes" << endl;
    cout << beta * 3600 << " <-- seconds";
}
