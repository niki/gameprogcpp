#pragma once

class Widget
{
public:
	int number = 0;
	
};

extern void  StudyCpp_MoveAndCopy_Test(void);
void someFunc(Widget&& rhs);	// ユニバーサル参照
void someFunc(Widget& rhs);		// 参照

