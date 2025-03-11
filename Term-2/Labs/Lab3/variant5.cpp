#include <iostream>

class Circle {
protected:
    float r;
public:
    Circle(float _r) : r(_r) {}

    void setR(float _r) {r = _r;}
    float getR() {return r;}
    
    virtual float function() const {return 3.14 * r * r;}
    virtual void print() const {
        std::cout << "Circle with radius = " << r  << ". Area = " << function() << std::endl;
    }
};

class Sphere : public Circle {
public:
    Sphere(float _r) : Circle(_r) {}
    float function() const override {return (4/3)*3.14*r*r*r;}
    void print() const override {
        std::cout << "Sphere with radius = " << r << ". Volume = " << function() << std::endl; 
    }
};

int main() {
    Circle c{2};
    Sphere s{3};
    
    Circle* p = &c;
    p->print();

    p = &s;
    p->print();
}

//
// Cube:
//  a
//  vtable
//  
//  b
//  print()
//  vtable
//
