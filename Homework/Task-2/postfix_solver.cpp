#include<bits/stdc++.h>

using namespace std;

double operation(char op, double a, double b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

double postfix_expression_solve(string input) {
    stack<double> digits;
    for (long unsigned int i = 0; i < input.length(); i++){
        if (input[i] != '_') 
        {
            if (isdigit(input[i])) 
            {
                string d;
                while (isdigit(input[i])) {
                    d += input[i];
                    i++;
                }
                i--;
                digits.push(stoi(d));
            }
            else 
            {
                int b = digits.top();
                digits.pop();
                int a = digits.top();
                digits.pop();
                digits.push(operation(input[i], a, b));
            }
        }
    }
    return digits.top();
}