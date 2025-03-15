#include"Deposit.cpp"
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<fstream>

int main() {
    std::vector<Deposit> depos;
    std::deque<Deposit> depos_q;
    std::ifstream in("/home/freeman/Coding/Study/Term-2/Labs/Lab4/input.txt");
    for(int i = 0; i < 3; i++) {
        std::string lbl, cur;
        int v;
        float r;
        in >> lbl >> v >> cur >> r;
        depos.push_back(Deposit(lbl, v, cur, r));
    }
    in.close();

    std::ofstream out("/home/freeman/Coding/Study/Term-2/Labs/Lab4/output.txt");
    out << "Default vector:\n";
    for (int i = 0; i < 3; i++) {
        out << depos[i].getLabel() << " " << depos[i].getValue() << " "
            << depos[i].getCurrencyType() << " " << depos[i].getRate() << "\n";
    }
    sort(depos.begin(), depos.end(), [](Deposit& a, Deposit& b){return a.getValue() < b.getValue();});
    out << "\nSorted vector:\n";
    for (int i = 0; i < 3; i++) {
        out << depos[i].getLabel() << " " << depos[i].getValue() << " "
            << depos[i].getCurrencyType() << " " << depos[i].getRate() << "\n";
    }

    copy(depos.begin(), depos.end(), depos_q.begin());
    
    out << "\nDeque:\n";
    for (int i = 0; i < 3; i++) {
        out << depos_q[i].getLabel() << " " << depos_q[i].getValue() << " "
            << depos_q[i].getCurrencyType() << " " << depos_q[i].getRate() << "\n";
    }
    return 0;
}
