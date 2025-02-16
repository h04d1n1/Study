#pragma once
#include<iostream>

class CString {
private:
    char* cstring;
public:
    CString(int);
    CString(const CString&);
    ~CString();
    CString operator++();
    CString operator--();
    CString operator+(const CString&) const;
    CString& operator=(const CString&);
    void readFromFile(std::string path);
};

CString operator*(const CString&, int);
CString operator*(int, const CString&);
std::ostream& operator<<(std::ostream&, const CString&);