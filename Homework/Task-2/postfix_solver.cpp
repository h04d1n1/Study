#include<string>
#include<cmath>
#include<map>
#include<iostream>
#include<stack>

using namespace std;

double operation(char op, double a, double b) {
    switch (op) {
        case '~': return a - b;
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

double functions(string func, double a) {
    map<string, double> f { // КОСТЫЛЬ :_
        {"sin", sin(a)}, {"cos", cos(a)},
        {"tg", sin(a)/cos(a)}, {"ctg", cos(a)/sin(a)}
    };
    return f[func];
}

double postfix_expression_solve(string s, map<char, double> vars) {
    stack<double> digits;
    for (long unsigned int i = 0; i < s.length(); i++){
        if (s[i] != ' ' && s[i] != ""[0])
        {
            if (isdigit(s[i])) 
            {
                string d = "";
                while (isdigit(s[i]) || s[i] == '.') {
                    d += s[i];
                    i++;
                }
                i--;
                digits.push(stof(d));
            }
            else
            {
                if (isalpha(s[i])) 
                {
                    string word = "";
                    while (isalpha(s[i])) 
                    {
                        word = word + s[i];
                        i++;
                    }
                    i--;
                    if (word.length() == 1) 
                    {
                        digits.push(vars[word[0]]);
                    }
                    else
                    {
                        double a = digits.top();
                        digits.pop();
                        digits.push(functions(word, a));
                    }
                }
                else if (digits.size() > 1) // КОСТЫЛЬ 2 :_
                {
                    double b = digits.top(), a = 0;
                    digits.pop();
                    if (s[i] != '~') 
                    {
                        a = digits.top();
                        digits.pop();
                    }
                    digits.push(operation(s[i], a, b));
                }
            }
        }
    }
    return digits.top();
}