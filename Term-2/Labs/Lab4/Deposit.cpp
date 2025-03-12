#include<string>
#include<fstream>

class Deposit {
    std::string label;
    int value;
    std::string currency_type;
    int rate;

    friend std::ofstream& operator<<(std::ofstream&, const Deposit&);

public:
    Deposit() : label(""), value(0), currency_type(""), rate(0) {}
    Deposit(std::string _label, int _value, std::string _type, int _rate) : label(_label), value(_value), currency_type(_type), rate(_rate) {}

    Deposit(const Deposit& other) : label(other.label), value(other.value), currency_type(other.currency_type), rate(other.rate) {}
    Deposit(Deposit&& other) : label(other.label), value(other.value), currency_type(other.currency_type), rate(other.rate) {}
    
    Deposit& operator=(const Deposit& other) {
        if (this != &other) {
            label = other.label;
            value = other.value;
            currency_type = other.currency_type;
            rate = other.rate;
        }
        return *this;
    }

    Deposit& operator=(Deposit&& other) noexcept {
        if (this != &other) {
            label = std::move(other.label);
            value = other.value;
            currency_type = std::move(other.currency_type);
            rate = other.rate;

            other.value = 0;
            other.rate = 0;
        }
        return *this;
    }

    std::string getLabel() const {return this->label;}
    int getValue() const {return this->value;}
    std::string getCurrencyType() const {return this->currency_type;}
    int getRate() const {return this->rate;}

};

std::ofstream& operator<<(std::ofstream& ofs, const Deposit& obj) {
    ofs << obj.label << " " << obj.value << " " << obj.currency_type << " " << obj.rate << std::endl;
    return ofs;
}
