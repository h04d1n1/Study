#pragma once
#include<string>
#include<map>
#include<stack>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>

using namespace std;

string indexToPostfix(string, string&);
double postfix_expression_solve(string, map<char, double>);