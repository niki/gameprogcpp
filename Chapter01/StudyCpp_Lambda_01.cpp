#include <algorithm>
#include <iostream>
#include <vector>
#include "StudyCpp_Lambda_01.h"


void Println(int x)
{
    std::cout << x << std::endl;
}


void StudyCpp_Lambda_01(void)
{
    {
        const int array[] = { 0, 1, 2, 3, 4 };
        std::vector<int> v(array, array + 5);

        auto c = std::count_if(v.begin(), v.end(), [](int elem) -> bool { return elem % 2 == 0; });
        std::cout << c << std::endl;

        // –ß‚è’lŒ^‚ÍA„˜_‚É”C‚¹‚Ä‚à—Ç‚¢
        auto c2 = std::count_if(v.begin(), v.end(), [](int elem) { return elem % 2 == 0; });
        std::cout << c2 << std::endl;
    }

    // C++03‚ÌŽÀ‘•

// 0`9 ‚ª“ü‚Á‚½ vector ‚ðì‚é
    {
        std::vector<int> v(10);
        std::generate_n(v.begin(), v.size(), GenerateIntegers());

        std::for_each(v.begin(), v.end(), Println);
        std::cout << "------" << std::endl;

        // ’l‚ª 3 ‚Ì”{”‚Ì—v‘f‚ðŽæ‚èœ‚­
        std::vector<int>::iterator it = std::remove_if(v.begin(), v.end(), IsMultiple(3));
        std::for_each(v.begin(), it, Println);
    }
}
