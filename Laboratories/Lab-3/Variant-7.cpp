/*
    Вариант 7
    Заданы целые числа a1, a2, a3, ..., an.
    Написать программу которая находит минимум этой последовательности
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned int n;
    cin >> n;
    int x;
    cin >> x;
    int mn = x;
    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        mn = min(mn, x);
    }
    cout << mn;
    return 0;
}
