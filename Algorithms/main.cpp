#include <iostream>
#include <string>
#include <stdlib.h> 

using namespace std;

struct Student
{
    string name = "";
    int mark = -1;
};

struct Node
{
    Student stud;
    Node *next = nullptr;
};

// ListItem *pF1=0;
struct List
{
    Node *first;
};

void addInList(Node* nw, List& lst)
{
    if (lst.first == nullptr) {
        lst.first = nw;
    }
    else {
        Node* cur = lst.first;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = nw;
    }
}

void removeFromList(string rm, List& lst) {
    Node* cur = lst.first;

    if (cur->stud.name == rm) {
        if (cur->next == nullptr) lst.first == nullptr;
        else lst.first = cur->next;
        return;
    }

    while (cur->next) {
        if (cur->next->stud.name == rm) {
            if (cur->next->next == nullptr) cur->next == nullptr;
            else cur->next = cur->next->next;
            return;
        }
        cur = cur->next;
    }
    cout << "Invalid name\n";
}

void printList(List& lst) {
    cout << "\nStudents:\n";
    int count = 1;
    Node* cur = lst.first;
    while (cur->next) {
        cout << count << ". " << "Name: " << cur->stud.name << ". Mark: " << cur->stud.mark << endl;
        cur = cur->next;
        count++;
    }
    cout << count << ". " << "Name: " << cur->stud.name << ". Mark: " << cur->stud.mark << endl;
    cout << "\n";
}

int main()
{
    List list = {0};
    int cmd = 1;
    Node* p;
    while (cmd != 0) {
        cout << "Input number:\n0. Exit\n1. Add student\n2. Remove student (by name)\n3. Search (by name)\n4. Show all students\n";
        cin >> cmd;
        if (cmd == 1) {
            p = new Node;
            cout << "Input student's name: "; cin >> p->stud.name;
            cout << "Input student's mark: "; cin >> p->stud.mark;
            addInList(p, list);
        }
        else if (cmd == 2) {
            cout << "Input name\n";
            string nm;
            cin >> nm;
            removeFromList(nm, list);
        }
        else if (cmd == 4) {
            printList(list);
        }
    }

    return 0;
}
