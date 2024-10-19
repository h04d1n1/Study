#include<bits/stdc++.h>

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

double postfix_expression_solve(string s) {
    stack<double> digits;
    for (long unsigned int i = 0; i < s.length(); i++){
        if (s[i] != ' ')
        {
            if (isdigit(s[i])) 
            {
                string d;
                while (isdigit(s[i])) {
                    d += s[i];
                    i++;
                }
                i--;
                digits.push(stoi(d));
            }

            else 
            {
                int b = digits.top(), a = 0;
                digits.pop();
                if (s[i] != '~') {
                    a = digits.top();
                    digits.pop();
                }
                digits.push(operation(s[i], a, b));
            }
        }
    }
    return digits.top();
}