#include<bits/stdc++.h>

using namespace std;

int priority(char op) {
    switch (op) {
        case '*': return 2;
        case '/': return 2;
        case '+': return 1;
        case '-': return 1;
        default: return 0;
    }
}

string indexToPostfix(string s) {
    stack<char> op_stack;
    string output ;
    for (long unsigned int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            string digit;
            while (isdigit(s[i])) {
                digit = digit + s[i];
                i++;
            }
            i--;
            output = output + digit + '_';
        }
        else if (s[i] == '(') {
            op_stack.push('(');
        }
        else if (s[i] == ')') {
            while (op_stack.top() != '(') {
                output = output + op_stack.top() + '_';
                op_stack.pop();
            }
            op_stack.pop();
        }
        else {
            while (!op_stack.empty() && priority(s[i]) <= priority(op_stack.top())) {
                output = output + op_stack.top() + '_';
                op_stack.pop();
            }
            op_stack.push(s[i]);
        }
    }
    while (!op_stack.empty()) {
        output = output + op_stack.top() + '_';
        op_stack.pop();
    }
    cout << output << endl;
    return output;
}