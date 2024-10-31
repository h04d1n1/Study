#include "C:\Coding\VSCode\Study\Algorithms\staff.hpp"

int main(int argc, const char** argv){
    int precision = 1e5;
    if (int(precision * NewtonReccurentSQRT(4, 2, 0.000001)) == int(precision * std::sqrt(4))) return 0;
    return 1;
}