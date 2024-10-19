#pragma once
#include <string>

using namespace std;

bool isOperator(char);
int priority(char);
string indexToPostfix(string);
double operation(char, double, double);
double postfix_expression_solve(string);