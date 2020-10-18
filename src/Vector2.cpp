#include "Vector2.h"
#include "Math.cpp"

using namespace BreathEngine;

/* Static properties */
const Vector2 Vector2::up = Vector2(0.0, 1.0);
const Vector2 Vector2::down = Vector2(0.0, -1.0);
const Vector2 Vector2::left = Vector2(-1.0, 0.0);
const Vector2 Vector2::right = Vector2(1.0, 0.0);
const Vector2 Vector2::one = Vector2(1.0, 1.0);
const Vector2 Vector2::zero = Vector2(0.0, 0.0);


/* Properties */

/* Constructors */
Vector2::Vector2(BR_FLOAT x, BR_FLOAT y)
	: x(x), y(y)
{
}

Vector2::~Vector2()
{
}

/* Public methods */
inline const BR_FLOAT Vector2::Magnitude()
{
	return BreathEngine::Sqrt(BreathEngine::Pow(x, 2) + BreathEngine::Pow(y, 2));
}

inline const Vector2 Vector2::Normalized()
{
	BR_FLOAT _mag = Magnitude();
	return Vector2(x / _mag, y / _mag);
}

inline const Vector2 Vector2::SqrMagnitude()
{
	Vector2 _norm = Normalized();
	return _norm * _norm;
}

/* Static methods */
const Vector2 Vector2::Lerp(Vector2 v1, Vector2 v2, BR_FLOAT factor)
{
	BR_FLOAT clampedFactor = BreathEngine::Clamp01(factor);
	return v1 + ((v2 - v1) / clampedFactor);
}

const Vector2 Vector2::LerpUnclamped(Vector2 v1, Vector2 v2, BR_FLOAT factor)
{
	return v1 + ((v2 - v1) / factor);
}

const Vector2 Vector2::Max(Vector2 v1, Vector2 v2)
{
	return Vector2(BreathEngine::Max(v1.x, v2.x), BreathEngine::Max(v1.y, v2.y));
}

const Vector2 Vector2::Min(Vector2 v1, Vector2 v2)
{
	return Vector2(BreathEngine::Min(v1.x, v2.x), BreathEngine::Min(v1.y, v2.y));
}


const float Vector2::Angle(Vector2 v1, Vector2 v2)
{
	BR_FLOAT _dot = Dot(v1.Normalized(), v2.Normalized());
	_dot = (_dot < -1.0 ? -1.0 : (_dot > 1.0 ? 1.0 : _dot));
	return acos(_dot);
}

const BR_FLOAT Vector2::Cross(Vector2 v1, Vector2 v2)
{
	return v1.z * v2.y - v1.y * v2.x;
}

const BR_FLOAT Vector2::Dot(Vector2 v1, Vector2 v2)
{
	return v1.x * v2.x + v1.y + v2.y;
}

const BR_FLOAT Vector2::Distance(Vector2 v1, Vector2 v2)
{
	return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y = v1.y, 2));
}

/* Operator overloading */
BR_FLOAT Vector2::operator[](BR_INT pos)
{
	switch (pos)
	{
	case 0: return x;
	case 1: return y;
	default:
		BR_ERROR("Vector2 index accesser position out of bounds, can only access position [0], [1]");
		return -1.0f;
	}
}

Vector2 Vector2::operator+(Vector2 v1)
{
	return Vector2(x + v1.x, y + v1.y);
}

Vector2 Vector2::operator-(Vector2 v1)
{
	return Vector2(x - v1.x, y - v1.y);
}

Vector2 Vector2::operator*(Vector2 v1)
{
	return Vector2(x * v1.x, y * v1.y);
}

Vector2 Vector2::operator/(Vector2 v1)
{
	return Vector2(x / v1.x, y / v1.y);
}

Vector2 Vector2::operator+(BR_FLOAT v1)
{
	return Vector2(x + v1, y + v1);
}

Vector2 Vector2::operator-(BR_FLOAT v1)
{
	return Vector2(x - v1, y - v1);
}

Vector2 Vector2::operator*(BR_FLOAT v1)
{
	return Vector2(x * v1, y * v1);
}

Vector2 Vector2::operator/(BR_FLOAT v1)
{
	return Vector2(x / v1, y / v1);
}
