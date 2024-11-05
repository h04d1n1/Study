/*
    Вариант 5.
    Определить первое число последовательности Фибоначчи, превышающее число X.
*/

#include <iostream>

using namespace std;

int main() {
    unsigned int first = 1, second = 1, x;
    cout << "Input X:" << endl;
    cin >> x;
    while (x >= second) {
        swap(first, second);
        second = first + second;
    }
    cout << "Answer: " << second;
    return 0;
}
