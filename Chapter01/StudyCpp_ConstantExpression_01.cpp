#include <iostream>
#include "StudyCpp_ConstantExpression_01.h"


static int f()
{
	return 1;
}



void StudyCpp_ConstantExpression_01(void)
{
	const int v1 = f();

	//constexpr int v2 = f();		// error

	int  x = f();
	const int v3 = x * 2;
	// constexpr int v4 = x * 2;	// error

	constexpr int y = 100;
	const int v5 = y * 2; 

	constexpr int v6 = y * 2;

}

