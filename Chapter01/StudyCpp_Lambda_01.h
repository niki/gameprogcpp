#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

class GenerateIntegers {
public:
    GenerateIntegers() : mValue(0) {}

    int operator()() {
        return mValue++;
    }

private:
    int mValue;
};


class IsMultiple {
public:
    IsMultiple(int x) : mX(x) {}

    inline bool operator()(int v) const
    {
        return v % mX == 0;
    }

private:
    int mX;
};


extern void StudyCpp_Lambda_01(void);
