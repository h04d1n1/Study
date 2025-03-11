#pragma once
#include<fstream>
#include<iostream>

class Vector {
private:
    double* array;
    int size;
    friend std::ofstream& operator<<(std::ofstream&, const Vector&);
    friend std::ifstream& operator>>(std::ifstream&, Vector&);
public:
    Vector(); // Default constructor
    Vector(const double*, int); // Parameterized constructor
    Vector(const Vector&); // Copy constructor
    Vector(Vector&&); // Move constructor
    ~Vector();

    int operator[](int); // operator [] 
    
    Vector& operator=(const Vector&); // Copy assignment operator 
    Vector& operator=(Vector&&); // Move assignment operator
    
    Vector operator+(const Vector&);
};

std::ofstream& operator<<(std::ofstream&, const Vector&); // Output vector to file
std::ifstream& operator>>(std::ifstream&, Vector&); // Input vector from file
