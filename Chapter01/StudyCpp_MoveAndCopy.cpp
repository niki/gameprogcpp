#include <iostream>
#include <exception>
#include <memory>
#include <utility>


#include "StudyCpp_MoveAndCopy.h"


#if 0
void someFunc(Widget obj)	// 実体
{
	std::cout << obj.number;

}
#endif


void someFunc(Widget* obj)	// ポインタ
{
	std::cout << obj->number;

}

void someFunc(Widget& obj)	// 参照
{
	std::cout << obj.number;

}

void someFunc(Widget&& obj)	// ユニバーサル参照
{
	std::cout << obj.number;

}




void StudyCpp_MoveAndCopy_Test(void)
{
	Widget obj;

	obj.number = 19681217;


	someFunc(&obj);				// ポインタ

	someFunc(obj);				// 参照

	someFunc(std::move(obj));	// ユニバーサル参照

}

