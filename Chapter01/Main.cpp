// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Game.h"
#include <iostream>
#include <string>


template <typename T>
T& add(T& value, const T& num)
{
	static T ret = value + num;
	return ret;
}

// クラスのテスト
class Vector3D {
public:
	void Add(Vector3D& v1, Vector3D& v2)
	{
		Vector3D r;
		r.x = v1.x + v2.x;
		r.y = v1.y + v2.y;
		r.z = v1.z + v2.z;
	}
	Vector3D()
	{
	}
	Vector3D(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	double x = 0.0f;
	double y = 0.0f;
	double z = 0.0f;

	Vector3D operator +(const Vector3D& r) const
	{
		Vector3D ret;
		ret.x = this->x + r.x;
		ret.y = this->y + r.y;
		ret.z = this->z + r.z;

		return ret;
	}
	Vector3D& operator =(const Vector3D& r) 
	{
		this->x = r.x;
		this->y = r.y;
		this->z = r.z;
	
		return *this;
	}
	Vector3D& operator +=(const Vector3D& r)
	{
		this->x += r.x;
		this->y += r.y;
		this->z += r.z;

		return *this;
	}
private:
};

void StudyMain()
{
	Vector3D v1(0.1f, 0.2f, 0.3f);
	Vector3D v2(0.4f, 0.5f, 0.6f);;
	Vector3D r;

#if 1
	v2 = v1;
	r = v1 + v2;

#else
	r.Add(v1, v2);
#endif
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



int main(int argc, char** argv)
{
	Game game;


	// 学習メイン

	//StudyMain();

	{
		int		a = 100;
		int		b = 200;
		int		c = add(a, b);
		printf("a=%d, b=%d c=%d \n ", a, b, c);
	}
	{
		float a = 100;
		float b = 200;
		float c = add(a, b);
		printf("a=%d, b=%d c=%d \n ", a, b, c);
	}

	bool success = game.Initialize();
	if (success)
	{
		game.RunLoop();
	}
	game.Shutdown();
	return 0;
}
