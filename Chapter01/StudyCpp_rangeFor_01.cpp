#include <iostream>
#include <list>
#include "StudyCpp_RangeFor_01.h"

void StudyCpp_RangeFor_01(void)
{
    int array[5] = { 0, 1, 2, 3, 4 };
    std::list<int> lst(array, array + 5);

    for (auto& n : array) {
        n += 10;
    }

    for (auto& n : lst) {
        n += 10;
    }
}

