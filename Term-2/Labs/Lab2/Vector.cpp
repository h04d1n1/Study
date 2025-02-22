// Variant 1
#include "Vector.hpp"

using namespace std;

Vector::Vector() : array(nullptr), size(0) {}

Vector::Vector(const double *other, int length) {
    size = length;
    array = new double[size];
    for(int i = 0; i < size; i++) array[i] = other[i];
}

Vector::Vector(const Vector& other) : size(other.size) {
    array = new double[size];
    for(int i = 0; i < size; i++) array[i] = other.array[i];
}

Vector::Vector(Vector&& other) : array(other.array), size(other.size) {
    other.array = nullptr;
    other.size = 0;
}

Vector::~Vector() {
    delete[] array;
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) return *this;
    delete[] array;
    size = other.size;
    array = new double[size];
    for(int i = 0; i < size; i++) array[i] = other.array[i];
    return *this;
}

Vector& Vector::operator=(Vector&& other) {
    swap(array, other.array);
    swap(size, other.size);
    return *this;
}

int Vector::operator[](int index) {
    return *(array + index);
}

Vector Vector::operator+(const Vector& other) {
    Vector newVec;
    newVec.size = size;
    newVec.array = new double[newVec.size];
    for (int i = 0; i < newVec.size; i++) newVec.array[i] = other.array[i] + array[i];
    return move(newVec);
}

ofstream& operator<<(ofstream& ofs, const Vector& obj) {
    ofs << obj.size << endl;
    if (obj.array) {
        for(int i = 0; i < obj.size; i++) ofs << obj.array[i] << " ";
    }
    ofs << endl;
    return ofs;
}

ifstream& operator>>(ifstream& ifs, Vector& obj) {
    delete[] obj.array;
    ifs >> obj.size;
    obj.array = new double[obj.size];
    for(int i = 0; i < obj.size; i++) ifs >> obj.array[i];
    return ifs;
}

int main() {
    Vector a;
    ifstream in("input.txt");
    in >> a;
    in.close();

    Vector b;
    ifstream in2("input.txt");
    in2 >> b;
    in.close();

    Vector c = a+b;
    ofstream out("output.txt");
    out << c;
    out.close();

    double *arr = new double[6]{1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    Vector z(arr, 6);
    Vector x(z); // Vector x = b; // Vector x; x = b;
    Vector y = move(z);

    ofstream out2("output.txt", ios::app);
    out2 << y;
    out2.close();
}
