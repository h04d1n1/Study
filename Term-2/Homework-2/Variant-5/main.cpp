#include <iostream>
#include "CString.cpp"

int main()
{
    CString empty_cstr;

    CString cstr("Hello, world!");

	CString a("Text for copying");
	CString b(a);
	b = a;

	CString c = std::move(a);
	c = CString("HI!");
	
	++cstr;
	std::cout << cstr << std::endl;
	--cstr;
	std::cout << cstr << std::endl;

	std::cout << cstr * 2 << std::endl << 5 * cstr << std::endl;

	CString add("QQQQQQ");
	std::cout << cstr + add << std::endl;

    return 0;
}
