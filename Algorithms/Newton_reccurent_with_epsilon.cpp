#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, p;
    cin >> a >> p;
    double x1 = a, x2 = ( (p-1)*x1 + a/pow(x1, p-1) ) / p;
    double eps;
    cin >> eps;
    int count = 1;
    while (abs(x2 - x1) > eps) {
        x1 = x2;
        x2 = ( (p-1)*x1 + a/pow(x1, p-1) ) / p;
        count++;
        // cout << x1 << endl;
    }
    cout << count;
    return 0;
}
