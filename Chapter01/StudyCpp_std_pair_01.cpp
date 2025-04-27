#include <utility>
#include <iostream>
#include <string>
#include <vector>

#include "StudyCpp_std_pair_01.h"



void StudyCpp_std_pair_01(void)
{

	using pairType = std::pair<int, std::string>;

	pairType 	makishima(1, "makishima");
	pairType	kikuchi(2, "kikuchi");
	std::vector<pairType> v;
	std::vector<pairType> v2{ makishima, kikuchi };


	v.push_back(makishima);
	v.push_back(kikuchi);

	

	std::cout << makishima.first << makishima.second << std::endl;
	std::cout << kikuchi.first << kikuchi.second << std::endl;

	for (auto& it : v) {
		std::cout << it.first << " " << it.second << " " << std::endl;
	}
	for (auto& it : v2) {
		std::cout << it.first << " " << it.second << " " << std::endl;
	}

}

