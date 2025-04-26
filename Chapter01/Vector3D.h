#pragma once


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
	const Vector3D& operator =(const Vector3D& r)
	{
		this->x = r.x;
		this->y = r.y;
		this->z = r.z;

		return *this;
	}
	const Vector3D& operator +=(const Vector3D& r)
	{
		this->x += r.x;
		this->y += r.y;
		this->z += r.z;

		return *this;
	}
private:
};

// テスト関数
extern void StudyCpp_Vector3D_01(void);
