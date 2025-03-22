#include"Deposit.cpp"
#include<iostream>

int main()
{
    std::unordered_set<Deposit, DepositHasher> st;
    std::ifstream in("../Term-2/Labs/Lab5/input.txt");
    for (int i = 0; i < 3; i++) {
        std::string lbl, cur;
        int v;
        float r;
        in >> lbl >> v >> cur >> r;
        std::cout << lbl;
        st.insert(Deposit(lbl, v, cur, r));
    }
    in.close();

    std::ofstream out("../Term-2/Labs/Lab5/output.txt");
    for (auto& pos : st) {
        out << pos.getLabel() << " " << pos.getValue() << " "
            << pos.getCurrencyType() << " " << pos.getRate() << "\n";
    }
    return 0;
}
