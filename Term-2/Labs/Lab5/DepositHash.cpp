#include"Deposit.cpp"

class DepositHasher {
    friend Deposit;
    hash<string> shash;
    hash<int> ihash;
    size_t operator()(const Deposit& obj) const {
        const size_t coef = 2946901;
        return (coef * coef * coef * shash(obj.label) +
                coef * coef * ihash(obj.value) +
                coef * shash(obj.currency.type) +
                ihash(obj.rate));
    }
}
