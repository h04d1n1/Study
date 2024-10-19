#include<bits/stdc++.h>

using namespace std;

int priority(char op) {
    switch (op) {
        case '~': return 3;
        case '*': return 2;
        case '/': return 2;
        case '+': return 1;
        case '-': return 1;
        case '(': return 0;
        default: return -1;
    }
}

string indexToPostfix(string s) {
    stack<char> op_stack;
    string output;
    for (long unsigned int i = 0; i < s.length(); i++) {

        if (isdigit(s[i])) {
            string digit;
            while (isdigit(s[i])) {
                digit = digit + s[i];
                i++;
            }
            i--;
            output = output + digit + " ";
        }

        else if (s[i] == '(') {
            op_stack.push('(');
        }

        else if (s[i] == ')') {
            while (op_stack.top() != '(') {
                output = output + op_stack.top();
                op_stack.pop();
            }
            op_stack.pop();
        }

        else {
            if (priority(s[i]) != 0) {

                if (s[i] == '-' && (i == 0 || (i > 1 && priority(s[i - 1]) != -1)))
                {
                    s[i] = '~';
                }

                while (!op_stack.empty() && priority(s[i]) <= priority(op_stack.top())) {
                    output = output + op_stack.top() + " ";
                    op_stack.pop();
                }
                op_stack.push(s[i]);

            }
        }

    }
    while (!op_stack.empty()) {
        output = output + op_stack.top() + " ";
        op_stack.pop();
    }
    cout << output << endl;
    return output;
}