#pragma once

#include <iostream>
#include <string>


template <typename T>
struct Rectangle {
	T left;
	T top;
	T right;
	T bottom;
};

template <typename T1, typename T2>
decltype(auto) createSquare(T1 x, T1 y, T2 length)
{
	const Rectangle<decltype(x - length / 2)> rc = {
		x - length / 2,
		y - length / 2,
		x + length / 2,
		y + length / 2
	};
	return rc;
}

template <typename R>
void printRectangle(const R& rc)
{
	std::cout << "["
		<< rc.left << ", "
		<< rc.top << ", "
		<< rc.right << ", "
		<< rc.bottom
		<< "]" << std::endl;
}


extern void StudyCpp_decltype_01(void);