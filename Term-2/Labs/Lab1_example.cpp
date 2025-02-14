#include <iostream>
#include <vector>
#include <string>

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

    return 0;
}