#include <iostream>
#include <cmath>

class Vector2D {
protected:
    double x;
    double y;
public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    virtual double length() const {
        return std::sqrt(x * x + y * y);
    }

    virtual void print() const {
        std::cout << "(" << x << ", " << y << ") -> " << length() << std::endl;
    }
};

class Vector3D : public Vector2D {
protected:
    double z;
public:
    Vector3D(double x = 0, double y = 0, double z = 0) : Vector2D(x, y), z(z) {}

    double length() const override {
        return std::sqrt(x * x + y * y + z * z);
    }

    void print() const override {
        std::cout << "(" << x << ", " << y << ", " << z << ") -> " << length() << std::endl;
    }
};

int main() {
    Vector2D v2(3, 4);
    Vector3D v3(3, 4, 5);
    Vector2D *p = &v2;

    std::cout << v2.length() << std::endl;
    std::cout << v3.length() << std::endl << std::endl;

    p->print(); // Вызов метода через указатель на базовый класс (Vector2D::print)
    p = &v3;    // Указатель на объект производного класса
    p->print(); // Вызов метода через указатель на производный класс (Vector3D::print)
                // Если бы не было виртуального метода, вызвался бы метод базового класса
    
    Vector2D v2_ = v3;
    v2_.print(); // Вызов виртуальной функции через имя объекта всегда разрешается статическим связыванием
                 // Поэтому вызывается метод базового класса (Vector2D::print)

    return 0;
}
