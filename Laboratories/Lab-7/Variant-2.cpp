/*
vector и list. 
*/


#include<iostream>
#include<vector>
#include<list>
#include<ctime>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
    srand(time(0));
    list<int> l;
    vector<int> v;

    for (int i = 0; i < 100000; i++) {
        int r = rand() % 100000;
        v.push_back(r);
        l.push_back(r);
    }

    int r = rand() % 100000;
    double start = clock();
    v.insert(v.begin(), r);
    double vec_time = (clock() - start) / CLOCKS_PER_SEC * 1000;
    start = clock();
    l.insert(l.begin(), r);
    double list_time = (clock() - start) / CLOCKS_PER_SEC * 1000;
    cout << "Vector insertion: " << vec_time << endl;
    cout << "List insertion: " << list_time << endl;
    cout << "Difference in insertion: " << fabs(vec_time - list_time) << endl;
    if (vec_time > list_time) cout << "List wins" << endl << endl;
    else if (vec_time == list_time) cout << "Equal" << endl << endl;
    else cout << "Vector wins" << endl << endl;

    r = rand() % 100000;
    start = clock();
    find(v.begin(), v.end(), r);
    vec_time = (clock() - start) / CLOCKS_PER_SEC * 1000;
    start = clock();
    find(l.begin(), l.end(), r);
    list_time = (clock() - start) / CLOCKS_PER_SEC * 1000;
    cout << "Vector finding: " << vec_time << endl;
    cout << "List finding: " << list_time << endl;
    cout << "Difference in finding: " << fabs(vec_time - list_time) << endl;
    if (vec_time > list_time) cout << "List wins" << endl << endl;
    else if (vec_time == list_time) cout << "Equal" << endl << endl;
    else cout << "Vector wins" << endl << endl;

    start = clock();
    v.pop_back();
    vec_time = (clock() - start) / CLOCKS_PER_SEC * 1000;
    start = clock();
    l.pop_back();
    list_time = (clock() - start) / CLOCKS_PER_SEC * 1000;
    cout << "Vector deleting: " << vec_time << endl;
    cout << "List deleting: " << list_time << endl;
    cout << "Difference in deleting last element: " << fabs(vec_time - list_time) << endl;
    if (vec_time > list_time) cout << "List wins" << endl << endl;
    else if (vec_time == list_time) cout << "Equal" << endl << endl;
    else cout << "Vector wins" << endl << endl;

    return 0;
}