#include <iostream>
#include <string>


#include "Vector3D.h"


void StudyCpp_Vector3D_01()
{
	Vector3D v1(0.1f, 0.2f, 0.3f);
	Vector3D v2(0.4f, 0.5f, 0.6f);;
	Vector3D r;

	v2 = v1;
	r = v1 + v2;

	{
		std::string str;
		str = " x = " + std::to_string(r.x)
			+ " y = " + std::to_string(r.y)
			+ " z = " + std::to_string(r.z);


		std::cout << str << std::endl;
	}
	{
		r += v1;
		std::string str;
		str = " x = " + std::to_string(r.x)
			+ " y = " + std::to_string(r.y)
			+ " z = " + std::to_string(r.z);


		std::cout << str << std::endl;
	}

}
