#include"Integer.hpp"

Integer::Integer() : value(0) {}

Integer::Integer(int _value) : value(_value) {}

int Integer::module5() {
    return value % 5;
}
