#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Auto
{
    string brand;
    double consumption;

public:
    Auto()
    {
        consumption = 0;
        brand = "";
    }
    Auto(string br, double cons)
    {
        brand = br;
        consumption = cons;
    }
    void set(string br, double cons)
    {
        brand = br;
        consumption = cons;
    }
    double getConsumptionForRun(double run) const
    {
        return consumption * run / 100.;
    }
    void print() const
    {
        cout << "Brand: " << brand << ". Fuel for 100 kilometers: " << consumption << endl;
    }
};

int main() {
    int n;
    ifstream in("auto.txt");
    in >> n;
    Auto *autos = new Auto[n];
    for (int i = 0; i < n; i++) {
        string tmp;
        int c;
        in >> tmp >> c;
        autos[i].set(tmp, c);
    }

    for (int i = 0; i < n; i++) {
        autos[i].print();
    }
    return 0;
}