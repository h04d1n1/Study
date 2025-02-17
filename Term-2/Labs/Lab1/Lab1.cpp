#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

class QudraticEquation 
{
    float a, b, c;
public:
    QudraticEquation(float _a = 0, float _b = 0, float _c = 0) {
        a = _a; b = _b; c = _c;
    }
    void setParameters(float _a, float _b, float _c) {
        a = _a; b = _b; c = _c;
    }
    void printParameters() const {
        cout << "A: " << a << " B: " << b << " C: " << c << endl;
    }
    float calculateDiscriminant() const {
        return b*b - 4*a*c;
    }
};

int main() {
    int n;
    ifstream in("test.txt");
    in >> n;
    QudraticEquation *dynamic_eqs = new QudraticEquation[n];
    vector<QudraticEquation> eqs;
    eqs.resize(n);
    for (int i = 0; i < n; i++) {
        float aa, bb, cc;
        in >> aa >> bb >> cc;
        eqs[i].setParameters(aa, bb, cc);
    }

    for (int i = 0; i < n; i++) {
        if (eqs[i].calculateDiscriminant() > 0) {
            eqs[i].printParameters();
        }
    }
    return 0;
}