#include<string>

class Deposit {
    std::string label;
    int value;
    std::string currency_type;
    float rate;

    friend std::ofstream& operator<<(std::ofstream&, const Deposit&);

public:
    Deposit();
    Deposit(std::string, int, std::string, float);

    Deposit(const Deposit&);
    Deposit(Deposit&&);
    
    Deposit& operator=(const Deposit&);
    Deposit& operator=(Deposit&&);

    int getValue();
};

std::ofstream& operator<<(std::ofstream&, const Deposit&);
