/*
Вариант 1
Проверить число на гипотезу Гольдбаха

*/


#include<iostream>
#include<vector>
#include<format>

using namespace std;

bool isPrime(unsigned int  n)
{
    if (n % 2 == 0) return n == 2;
    unsigned int d = 3;
    while (d*d <= n && n % d != 0)
    {
        d += 2;
    }
    return d*d > n;
}

int main()
{
    int digit;
    bool flag = false;
    cin >> digit;
    vector<int> primes;
    for (int i = 2; i < digit; i++)
    {
        if (isPrime(i) && flag == false) 
        {
            int current = i;
            primes.push_back(current);
            for (int j = 0; j < primes.size(); j++) 
            {
                if (current + primes[j] == digit) {
                    flag = true;
                    cout << current << ' ' << primes[j];
                }
            }
        }
    }
    if (!flag) cout << "False";
    return 0;
}