#include<string>
#include<map>
#include<stack>
#include<iostream>

using namespace std;

int priority(char op) {
    map<char, int> ops
    {
        {'~', 3}, 
        {'*', 2}, {'/', 2},
        {'+', 1}, {'-', 1},
        {'(', 0}
    };
    if (ops.count(op)) {
        return ops[op];
    }
    return -1;
}

string indexToPostfix(string s, string& variables) {
    stack<char> op_stack;
    string output;

    for (long unsigned int i = 0; i < s.length(); i++) {

        if (isdigit(s[i])) {
            string digit;
            while (isdigit(s[i]) || s[i] == '.') {
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
                output = output + op_stack.top()  + " ";
                op_stack.pop();
            }
            op_stack.pop();
        }

        else {
            if (isalpha(s[i])) {
                string word;
                while (isalpha(s[i])) {
                    word = word + s[i];
                    i++;
                }
                i--;
                if (word.length() == 1) {
                    variables = variables + s[i];
                    output = output + s[i] + " ";
                }
                else {
                    string sub_input = "";
                    int count = 1;
                    i+=2;
                    while (count != 0) {
                        if (s[i] == ')') count-=1;
                        if (s[i] == '(') count+=1;
                        if (count != 0) sub_input = sub_input + s[i];
                        i++;
                    }
                    while (!op_stack.empty() && 3 <= priority(op_stack.top())) {
                        output = output + op_stack.top() + " ";
                        op_stack.pop();
                    }
                    op_stack.push(s[i]);
                    output = output + indexToPostfix(sub_input, variables) + word + " ";
                }
            }
            else if (priority(s[i]) != -1) {

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
    return output;
}