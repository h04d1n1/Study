#pragma once
#include<iostream>

class CString {
private:
    char* cstring;
    size_t length;

public:
    CString(const char*);
    CString(const CString&);
    ~CString();
    CString& operator++();
    CString& operator--();
    CString operator+(const CString&) const;
    CString& operator=(const CString&);
    CString operator*(int);
    void readFromFile(std::string path);
};

CString operator*(int, const CString&);
std::ostream& operator<<(std::ostream&, const CString&);