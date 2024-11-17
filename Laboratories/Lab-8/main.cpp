/*
Объект-сотрудник: ФИО, дата приема на работу, должность, базовый оклад.
Сортировка по окладу, двухсвязный некольцевой список.
Метод прямого выбора
*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Employee
{
    int zp = 0;
    string fio = "";
    string data_of_signing = "";
    string specialization = "";
};

struct ListNode
{
    Employee emp;
    ListNode *next = {nullptr}, *prev = {nullptr};
};

struct List 
{
    ListNode *first;
};

void addElement(List &lst, ListNode *p)
{
    if (lst.first == 0)
    {
        lst.first = p;
    }
    else
    {
        ListNode* cur = lst.first;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = p;
        p->prev = cur;
    }
}

void print(ListNode *head)
{
    if (head == nullptr) {
        cout << 0 << endl;
    }
    else {
        while(head->next != nullptr) {
            cout << "FIO: " << head->emp.fio << " | Salary: " << head->emp.zp
         << " | Spec: " << head->emp.specialization << endl;
            head = head->next;
        }
        cout << "FIO: " << head->emp.fio << " | Salary: " << head->emp.zp
         << " | Spec: " << head->emp.specialization << endl;
    }
}

List sort(List lst) {
    List res = {0};
    ListNode *mn = lst.first;
    ListNode *cur = lst.first;

    while (lst.first->next != nullptr) {
        cur = mn = lst.first;

        // Find mn
        while (cur->next != nullptr) {
            if (cur->emp.zp < mn->emp.zp) mn = cur;
            cur = cur->next;
        }
        if (cur->emp.zp < mn->emp.zp) mn = cur;

        // Remove mn
        if (mn == lst.first) {
            if (lst.first->prev == nullptr) res.first = mn;
            lst.first = lst.first->next;
        }
        else {
            if (mn->next == nullptr) {
                mn->prev->next = nullptr;
            }
            else {
                mn->next->prev = mn->prev;
                mn->prev->next = mn->next;
            }

            // Insert mn
            if (lst.first->prev == nullptr) {
                res.first = mn;
                lst.first->prev = mn;
                mn->next = lst.first;
                mn->prev = nullptr;
            }
            else {
                mn->prev = lst.first->prev;
                mn->next = lst.first;
                lst.first->prev->next = mn;
                lst.first->prev = mn;
            }
        }
    }
    return res;
}

string names[] = {"Ivanov", "Petrov", "Sidorov", "Kuznetsov",
                "Ivanova", "Petrova", "Sidorova", "Kuznetsova", "Vasilev",
                "Vasileva"};
string specs[] = {"test", "devOps", "BoomBeach", "front"};         

int main()
{
    srand(time(0));
    List l1 = {0};
    ListNode *p;
    ListNode *back;
    for (int i = 0; i < 4; i++)
    {
        cout << "Input Employee date of signing: " << endl;
        string name = names[rand() % 10], spec = specs[rand() % 4], date;
        int z = rand() % 1000;
        cin >> date;
        p = new ListNode;
        p->emp.fio = name;
        p->emp.specialization = spec;
        p->emp.data_of_signing = date;
        p->emp.zp = z;
        addElement(l1, p);
        back = p;
    }
    cout << endl;
    print(l1.first);
    l1 = sort(l1);
    cout << endl << "sorted" << endl;
    print(l1.first);
    return 0;
}
