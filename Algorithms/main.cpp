#include <iostream>
#include <string>

using namespace std;

struct Man
{
    int N;
    string fio;
};

struct ListItem
{
    Man man;
    ListItem *pNext, *pPred;
};

// ListItem *pF1=0;
struct List
{
    ListItem *pFirst;
};

void addInList(List &list, ListItem *p, bool flag = true) // flag = true Добавляем в начало списка
{
    if (list.pFirst == 0)
    {
        list.pFirst = p->pNext = p->pPred = p;
    }
    else
    {
        p->pNext = list.pFirst;
        p->pPred = list.pFirst->pPred;
        list.pFirst->pPred->pNext = p;
        list.pFirst->pPred = p;
        if (flag) list.pFirst = p;
    }
}

void addAfterElement(ListItem *pZad, ListItem *p)
{
    p->pNext = pZad->pNext;
    p->pPred = pZad;
    pZad->pNext->pPred = p;
    pZad->pNext = p;
}

ListItem *remove(List &list, ListItem *p)
{
    if (list.pFirst == 0 || p == 0)
        return 0;
    if (list.pFirst->pNext == list.pFirst)
    {
        if (p == list.pFirst)
        {
            list.pFirst = 0;
            return p;
        }
        else return 0;
    }
    if (p == list.pFirst) list.pFirst = list.pFirst->pNext;
    p->pPred->pNext = p->pNext;
    p->pNext->pPred = p->pPred;
    return p;
}

void print(List list)
{
    ListItem *p = list.pFirst;
    do {
        cout << endl << p->man.fio << ' ' << p->man.N;
        p = p->pNext;
    } while (p != list.pFirst);
}

string str[] = {"Ivanov", "Petrov", "Sidorov", "Kuznecov",
                "Ivanova", "Petrova", "Sidorova", "Kuznecova", "Vasilev",
                "Vasileva"};

int main()
{
    List l1 = {0};
    ListItem *p;
    for (int i = 1; i < 10; i++)
    {
        p = new ListItem;
        p->man.N = rand() % 100;
        p->man.fio = str[rand() % 10];
        addInList(l1, p, false);
    }
    cout << "Before sort" << endl;
    print(l1);
    
    p = l1.pFirst->pNext; // Начинаем со второго элемента
    do
    {
        ListItem *p1 = p->pNext; // Запоминаем следующий элемент
        ListItem *p2 = l1.pFirst;  // Просматриваем элементы предшествующие p
        do
        {
            if (p2->man.N > p->man.N) // Элемент p нужно вставить перед p2 (сортировка по возрасту)
            {
                p = remove(l1, p); // Извлекаем элемент
                if (p == 0)
                {
                    cout << "List Error!!!!";
                    system("pause");
                    return 0;
                }
                if (p2 == l1.pFirst) addInList(l1, p, true); // Вставляем в списка 
                else addAfterElement(p2->pPred, p);
                break;
            }
            p2 = p2->pNext; // Переход к след. элементу
        } while (p2 != p);
        p = p1; // Переход к след. элементу
    } while (p != l1.pFirst);
    cout << endl << endl << "After sort" << endl;
    print(l1);
    return 0;
}
