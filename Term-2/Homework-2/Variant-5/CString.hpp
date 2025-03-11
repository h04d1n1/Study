#pragma once
#include<iostream>

class CString {
    private:
        char* str;
        size_t length;
        friend CString operator*(int, const CString&);
        friend std::ostream& operator<<(std::ostream& os, const CString& obj);
    
    public:
        // Default constructor
        CString();
    
        // Parameterized constructor
        CString(const char* s);
    
        // Copy constructor
        CString(const CString& other);
    
        // Move constructor
        CString(CString&& other) noexcept;
    
        // Destructor
        ~CString();
    
        // Copy assignment operator
        CString& operator=(const CString& other);
    
        // Move assignment operator
        CString& operator=(CString&& other) noexcept;
    
        // Increment operator
        CString& operator++();
    
        // Decrement operator
        CString& operator--();
    
        // Addition operator
        CString operator+(const CString& other) const;
    
        // Multiplication operator
        CString operator*(const int multiplier) const;
    
        // Get length of the string
        size_t getLength() const;
    
        // Get C-style string
        const char* getCString() const;
    };

CString operator*(int, const CString&);
std::ostream& operator<<(std::ostream&, const CString&);
