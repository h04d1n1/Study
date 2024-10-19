#include<bits/stdc++.h>
#include"functions.h"

using namespace std;

int main(){
    string expression;
    getline(cin, expression);
    expression.erase(remove(expression.begin(), expression.end(), ' '), expression.end());
    expression = indexToPostfix(expression);
    cout << postfix_expression_solve(expression) << endl;
    return 0;
}