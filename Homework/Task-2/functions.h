#pragma once
#include<string>

using namespace std;

int priority(char);
string indexToPostfix(string);
double operation(char, double, double);
double postfix_expression_solve(string);