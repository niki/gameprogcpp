#include "StudyCpp_decltype_01.h"

void StudyCpp_decltype_01(void)
{
	auto rc1 = createSquare(0, 0, 10);
	auto rc2 = createSquare(0, 0, 9.8);
	auto rc3 = createSquare(0.5, 0.5, 10);

	printRectangle(rc1);
	printRectangle(rc2);
	printRectangle(rc3);
}
