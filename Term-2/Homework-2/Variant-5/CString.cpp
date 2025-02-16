//#include "CString.hpp"
#include <cstring>
#include <iostream>

class CString {
private:
    char* str;
    size_t length;
    friend CString operator*(int, const CString&);
    friend std::ostream& operator<<(std::ostream& os, const CString& obj);

public:
    // Default constructor
    CString() : str(nullptr), length(0) {}

    // Parameterized constructor
    CString(const char* s) {
        length = std::strlen(s);
        str = new char[length + 1];
        std::strcpy(str, s);
    }

    // Copy constructor
    CString(const CString& other) : length(other.length) {
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    // Move constructor
    CString(CString&& other) noexcept : str(other.str), length(other.length) {
        other.str = nullptr;
        other.length = 0;
    }

    // Destructor
    ~CString() {
        delete[] str;
    }

    // Copy assignment operator
    CString& operator=(const CString& other) {
        if (this == &other) return *this; // Self-assignment check

        delete[] str;
        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);

        return *this;
    }

    // Move assignment operator
    CString& operator=(CString&& other) noexcept {
        if (this == &other) return *this;

        delete[] str;
        str = other.str;
        length = other.length;

        other.str = nullptr;
        other.length = 0;

        return *this; // CString nw = std::move(old);
    }

    // Increment operator
    CString& operator++() {
        length++;
        std::strcat(str, "!");
        return *this;
    }

    // Decrement operator
    CString& operator--() {
        if (length > 0) {
            length--;
            str[length] = '\0'; // Because C-style string ends with '\0'
        }
        return *this;
    }

    // Addition operator
    CString operator+(const CString& other) const {
        CString newStr("");
        newStr.length = length + other.length;
        newStr.str = new char[newStr.length + 1];
        std::strcpy(newStr.str, str);
        std::strcat(newStr.str, other.str);
        return std::move(newStr);
    }

    // Multiplication operator
    CString operator*(const int multiplier) const {
        if (multiplier == 0) {
            return CString("");
        }
        CString newStr;
        newStr.length = length * multiplier;
        newStr.str = new char[newStr.length + 1];
        for (int i = 0; i < multiplier; ++i) {
            std::strcat(newStr.str, str);
        }
        return std::move(newStr);
    }

    // Get length of the string
    size_t getLength() const {
        return length;
    }

    // Get C-style string
    const char* getCString() const {
        return str;
    }
};

std::ostream& operator<<(std::ostream& os, const CString& obj) {
    if (obj.str) {
        os << obj.str;
    }
    return os;
}

CString operator*(const int multiplier, const CString& other) {
    if (multiplier == 0) {
        return CString("");
    }
    CString newStr;
    newStr.length = other.length * multiplier;
    newStr.str = new char[newStr.length + 1];
    for (int i = 0; i < multiplier; ++i) {
        std::strcat(newStr.str, other.str);
    }
    return std::move(newStr);
}

int main() {
    return 0;
}
