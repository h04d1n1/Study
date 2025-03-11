#include <iostream>

class Point2D {
protected:
    float x, y;
public:
    Point2D(float x1, float x2): x(x1), y(x2) {}

    void setX(float _x) {x = _x;}
    void setY(float _y) {y = _y;}

    float getX() const {return x;}
    float getY() const {return y;}

    virtual void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

class Point3D : public Point2D {
protected:
    float z;
public:
    Point3D(float x1, float x2, float x3) : Point2D(x1, x2), z(x3) {}

    void setZ(float _z) {z = _z;}

    float getZ() const {return z;}

    void print() const override {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

int main() {
    Point2D p2{2, 3};
    Point3D p3{4, 5, 6};

    Point2D* pp = &p2;
    pp->print();

    pp = &p3;
    pp->print();
    return 0;
}

