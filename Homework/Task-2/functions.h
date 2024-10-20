#pragma once
#include<string>

using namespace std;

string indexToPostfix(string, string&);
double postfix_expression_solve(string, map<char, double>);