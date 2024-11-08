/*
Определите, сколько студентов не имеет задолженность
*/

#include<iostream>
#include<vector>

using namespace std;

struct subject {
    string title;
    int mark;
    subject(string ti = "", int ma = 0) {
        this->title = ti;
        this->mark = ma;
    }
};

struct student {
    string name;
    vector<subject> disciplines;
    student(string name = "", vector<subject> disciplines = {}) {
        this->name = name;
        this->disciplines = disciplines;
    }
};

int main() {
    int counter = 0;
    cout << "Input number of students: ";
    int n;
    cin >> n;
    vector<student> group(n);
    for (int i = 0; i < n; i++) {
        cout << "Input name of Student " << i + 1 << " : ";
        string nam;
        cin >> nam;
        vector<subject> discs(4);
        bool flag = false;

        for (int j = 0; j < 4; j++) {
            cout << "Subject " << j+1 << " Title: ";
            string t;
            int m;
            cin >> t;
            cout << "And Mark: ";
            cin >> m;
            if (m < 60) {flag = true;}
            discs.push_back(subject(t, m));
        }
        
        if (flag) counter++;
        group.push_back(student(nam, discs));
    }
    cout << counter << endl;
    return 0;
}