#include <iostream>

#include "StudyCpp_RawString_01.h"


void StudyCpp_RawString_01(void)
{
	// StudyCpp_rawString_01



	const char s[] = R"!!!((3 + 2) * 2)!!!";
	const char* raw_string = R"(これは生文字列リテラルの例です。
改行や\tタブもそのまま扱われます。)";


	std::cout << s << std::endl;
	std::cout << raw_string << std::endl;

	{	// 数値リテラル

		long long  value = 1'000'000;		// 百万円	
		long long  value2 = 100'000'000;	// 一億円

		std::cout << value << std::endl << value2 << std::endl;
	}

	{	// ２進数リテラル
		long long  memoryPtr = 0b01000000'00000000'00000000'00000000;

		std::cout << memoryPtr;
	}
}

