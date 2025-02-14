#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

struct School {
    string town = "";
    int number = 0;
    string special = "";
    int students_number = 0;
};

int main(int argc, const char* argv[]) {
    if (argc != 3) {
        cout << "Input 2 parameters";
        return 0;
    }

    const string mode(argv[1]);
    const string open_mode(argv[2]);
    int n;

    if (mode == "write") {
        cout << "Input number of Schools: \n";
        cin >> n;
        vector<School> schs(n);
        for (int i = 0; i < n; i++) {
            cout << "Input Town: ";
            cin >> schs[i].town;
            cout << "Input number of school: ";
            cin >> schs[i].number;
            cout << "Input speciality of school: ";
            cin >> schs[i].special;
            cout << "Input number of students: ";
            cin >> schs[i].students_number;
            cout << endl;
        }
        if (open_mode == "text") {
            ofstream out("../../../Schools.dat");
            out << n << endl;
            for (auto pos : schs) {
                out << pos.town << endl << pos.number << endl << pos.special << endl << pos.students_number;
            }
            out.close();
        }
        else if (open_mode == "binary") {
            ofstream out("../../../Schools.dat", ios::binary);
            out.write((char*) &n, sizeof n);
            for (auto pos : schs) {
                out << pos.town << ends;
                out.write((char*) &pos.number, sizeof pos.number);
                out << pos.special << ends;
                out.write((char*) &pos.students_number, sizeof pos.students_number);
            }
            out.close();
        }
    }
    else if (mode == "read") {
        if (open_mode == "text") {
            ifstream in("../../../Schools.dat");
            in >> n;
            for (int i = 0; i < n; i++) {
                string town; in >> town;
                int number; in >> number;
                string spec; in >> spec;
                int studs; in >> studs;
                cout << "Town of school " << i+1 << " : " << town << endl;
                cout << "Number of school " << i+1 << " : " << number << endl;
                cout << "Speciality of school " << i+1 << " : " << spec << endl;
                cout << "Number of students in school " << i+1 << " : " << studs << endl;
            }
            in.close();
        }
        else if (open_mode == "binary") {
            ifstream in("../../../Schools.dat", ios::binary);
            in.read((char *)&n, sizeof(n));
            vector<School> schs(n);
            for (auto &pos : schs) {
                getline(in, pos.town, '\0');
                in.read((char *)&pos.number, sizeof(pos.number));
                getline(in, pos.special, '\0');
                in.read((char *)&pos.students_number, sizeof(pos.students_number));
                cout << "School: " << pos.town << ' ' << pos.number
                    << ' ' << pos.special << ' ' << pos.students_number << endl;
            }
        }
    }
    return 0;
}