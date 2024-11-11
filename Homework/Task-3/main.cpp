#include<fstream>
#include<iostream>

using namespace std;

string intToBin(int i) {;}
int binToInt(string b) {;}

int main(int argc, const char* argv[]) {
    if (argc != 3) {
        cerr << "Need MODE and FILE as parameters!" << endl;
        return 2;
    }
    const string mode(argv[1]);
    const string file(argv[2]);

    ifstream encrypted_file("../../../Homework/Task-3/encrypted.txt");

    if (mode == "encryption") {
        cout << "Type message to encrypt:" << endl;
        string message;
        getline(cin, message);
        
    }

    return 0;
}