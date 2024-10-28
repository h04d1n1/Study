#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <format>

using namespace std;

double linear_to_fraction(vector<int> v) {
    double e = v.back();
    for (int i = v.size(); i > -1; i--) {
        e = v[i] + 1.0 / e;
        // cout << e << endl;
    }
    return e;
}

int main() {
    double eps;
    cin >> eps;
    cout << fixed << setprecision(-log10(eps) + 5);
    vector<int> linear = {2, 1, 2};
    double last = 2 + 1./2;
    double current = 2 + 1./(1 + 1./2);
    int iterations = 2;
    while (fabs(last - current) >= eps || last - current == 0) {
        last = current;

        if (linear.size() % 3 == 2) linear.push_back(linear[linear.size() - 3] + 2);
        else linear.push_back(1);

        current = linear_to_fraction(linear);
        iterations++;
        // cout << last << ' ' << current << ' ' << fabs(last - current) << endl; // Для наглядности сравнения
    }
    cout << endl << "Exponent for precision " << eps << " is " << current << endl << "Linear: ";
    for (int i = 0; i < linear.size(); i++) cout << setprecision(1) << linear[i] << ' ';
    cout << endl << "Iterations: " << iterations << endl;
    return 0;
}