#pragma once

#include <cstddef>

template <std::size_t SIZE>
class Buffer {
    static_assert(SIZE > 0, "buffer size must greater than 0");
};

extern void StudyCpp_static_assert_01(void);
