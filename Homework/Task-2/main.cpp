#include<map>
#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include"functions.h"

using namespace std;

int main(){
    string expression, vars;
    getline(cin, expression);

    expression.erase(remove(expression.begin(), expression.end(), ' '), expression.end());
    expression = indexToPostfix(expression, vars);

    map<char, double> variables{
        {'p', 3.14159265358979323846}
    };
    for (char var : vars) {
        if (variables.count(var) == 0) {
            cout << "Variable " << char(toupper(var)) << ": \n";
            cin >> variables[var];
        }
    }

    cout << fixed << setprecision(6) << "The Answer is...\n" << postfix_expression_solve(expression, variables) << endl;
    
    return 0;
}