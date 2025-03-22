/*2
Объект- банковский
вклад (поля:
название, сумма
вклада, тип валюты,
ставка в % годовых)

Исходный
контейнер vector,
копируем в deque

Сортировка по
сумме вклада
*/

#include<string>
#include<fstream>
#include<unordered_set>

class Deposit
{
    std::string label;
    int value;
    std::string currency_type;
    int rate;

    friend std::ofstream& operator<<(std::ofstream&, const Deposit&);

public:
    Deposit() : label(""), value(0), currency_type(""), rate(0) {}
    Deposit(std::string _label, int _value, std::string _type, int _rate) : label(_label), value(_value), currency_type(_type), rate(_rate) {}

    Deposit(const Deposit& other) : label(other.label), value(other.value), currency_type(other.currency_type), rate(other.rate) {}
    Deposit(Deposit&& other) : label(std::move(other.label)), value(other.value), currency_type(std::move(other.currency_type)), rate(other.rate)
    {
        other.value = 0;
        other.rate = 0;
    }

    Deposit& operator=(const Deposit& other)
    {
        if (this != &other) {
            label = other.label;
            value = other.value;
            currency_type = other.currency_type;
            rate = other.rate;
        }
        return *this;
    }

    Deposit& operator=(Deposit&& other) noexcept
    {
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

    bool operator<(const Deposit& obj) const
    {
        return this->value < obj.value;
    }

    bool operator==(const Deposit& obj) const
    {
        return label == obj.label && value == obj.value && currency_type == obj.currency_type && rate == obj.rate;
    }

    std::string getLabel() const { return this->label; }
    int getValue() const { return this->value; }
    std::string getCurrencyType() const { return this->currency_type; }
    int getRate() const { return this->rate; }
};

std::ofstream& operator<<(std::ofstream& ofs, const Deposit& obj)
{
    ofs << obj.getLabel() << " " << obj.getValue() << " " << obj.getCurrencyType() << " " << obj.getRate() << std::endl;
    return ofs;
}

// Хэш-функция для Deposit
struct DepositHasher
{
    std::size_t operator()(const Deposit& obj) const
    {
        std::hash<std::string> shash;
        std::hash<int> ihash;
        const size_t coef = 2946901;
        return (
            coef * coef * coef * shash(obj.getLabel()) +
            coef * coef * ihash(obj.getValue()) +
            coef * shash(obj.getCurrencyType()) +
            ihash(obj.getRate()));
    }
};