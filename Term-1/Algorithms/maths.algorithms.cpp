#include "staff.hpp"

using namespace std;

double linear_to_fraction(vector<int> v) {
    double e = v.back();
    for (int i = v.size(); i > -1; i--) {
        e = v[i] + 1.0 / e;
    }
    return e;
}

double ExponentFraction(double eps) {
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
    }
    return current;
}

double NewtonReccurentSQRT(int a, int p, double eps) {
    double x1 = a, x2 = ( (p-1)*x1 + a/pow(x1, p-1) ) / p;
    int count = 1;
    while (abs(x2 - x1) > eps) {
        x1 = x2;
        x2 = ( (p-1)*x1 + a/pow(x1, p-1) ) / p;
        count++;
        // cout << x1 << endl;
    }
    return x2;
}