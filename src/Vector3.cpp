#include "Vector3.h"

#include <math.h>

using namespace BreathEngine;

/* Static properties */
const Vector3 Vector3::forward = Vector3(0.0, 0.0, 1.0);
const Vector3 Vector3::back = Vector3(0.0, 0.0, -1.0);
const Vector3 Vector3::up = Vector3(0.0, 1.0, 0.0);
const Vector3 Vector3::down = Vector3(0.0, -1.0, 0.0);
const Vector3 Vector3::left = Vector3(-1.0, 0.0, 0.0);
const Vector3 Vector3::right = Vector3(1.0, 0.0, 0.0);
const Vector3 Vector3::one = Vector3(1.0, 1.0, 1.0);
const Vector3 Vector3::zero = Vector3(0.0, 0.0, 0.0);


/* Properties */

/* Constructors */
Vector3::Vector3(BR_FLOAT x, BR_FLOAT y, BR_FLOAT z)
	: x(x), y(y), z(z)
{
}

Vector3::~Vector3()
{
}

/* Public methods */
inline const BR_FLOAT Vector3::Magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

inline const Vector3 Vector3::Normalized()
{
	BR_FLOAT _mag = Magnitude();
	return Vector3(x/ _mag, y/ _mag, z/ _mag);
}

inline const Vector3 Vector3::SqrMagnitude()
{
	Vector3 _norm = Normalized();
	return _norm * _norm;
}

/* BR_FLOAT methods */
const float Vector3::Angle(Vector3 v1, Vector3 v2)
{
	BR_FLOAT _dot = Dot( v1.Normalized(), v2.Normalized() );
	_dot = (_dot < -1.0 ? -1.0 : (_dot > 1.0 ? 1.0 : _dot));
	return acos(_dot);
}

const Vector3 Vector3::Cross(Vector3 v1, Vector3 v2)
{
	BR_FLOAT _x = v1.y * v2.z - v1.z * v2.y;
	BR_FLOAT _y = v1.z * v2.x - v1.x * v2.z;
	BR_FLOAT _z = v1.x * v2.y - v1.y * v2.x;
	return Vector3(_x, _y, _z);
}

const BR_FLOAT Vector3::Dot(Vector3 v1, Vector3 v2)
{
	BR_FLOAT _product = 0;
	for (int i = 0; i < 3; i++)
		_product = _product + v1[i] * v2[i];
	return _product;
}

const BR_FLOAT Vector3::Distance(Vector3 v1, Vector3 v2)
{
	return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y = v1.y, 2) + pow(v2.z - v1.z, 2));
}

/* Operator overloading */
BR_FLOAT Vector3::operator[](int pos)
{
	switch (pos)
	{
	case 0: return x;
	case 1: return y;
	case 2: return z;
	default: 
		BR_ERROR("Vector3 index accesser position out of bounds, can only access position [0], [1] and [2]"); 
		return -1.0f;
	}
}

Vector3 Vector3::operator+(Vector3& v1)
{
	return Vector3(x + v1.x, y + v1.y, z + v1.z);
}

Vector3 Vector3::operator-(Vector3& v1)
{
	return Vector3(x - v1.x, y - v1.y, z - v1.z);
}

Vector3 Vector3::operator*(Vector3& v1)
{
	return Vector3(x * v1.x, y * v1.y, z * v1.z);
}

Vector3 Vector3::operator/(Vector3& v1)
{
	return Vector3(x / v1.x, y / v1.y, z / v1.z);
}
