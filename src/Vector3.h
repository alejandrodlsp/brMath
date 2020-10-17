#pragma once

#include <iostream>
#define BR_ERROR(x) std::cout << x << std::endl; 

class Vector3
{
public:
	/* Static properties */
	const static Vector3 forward;
	const static Vector3 back;
	const static Vector3 up;
	const static Vector3 down;
	const static Vector3 left;
	const static Vector3 right;
	const static Vector3 one;
	const static Vector3 zero;

	/* Properties */
	float x, y, z;
	// TODO: [0], [1], [2] postional accessors

	/* Constructors */
	Vector3(float x, float y, float z);
	// TODO: Vector2 based constructors
	~Vector3();


	/* Public methods */
	const inline float Magnitude();
	const inline Vector3 Normalized();
	const inline Vector3 SqrMagnitude();
	const char* str();

	/* Static methods */
	const static float Angle(Vector3 from, Vector3 to);
	const static Vector3 Cross(Vector3 v1, Vector3 v2);
	const static float Dot(Vector3 v1, Vector3 v2);
	const static float Distance(Vector3 from, Vector3 to);

	// TODO: Lerp
	// TODO: Lerp unclamped
	const static Vector3 Max(Vector3 v1, Vector3 v2);
	const static Vector3 Min(Vector3 v1, Vector3 v2);
	// TODO: Move towards


	/* Operator overloading */
	float operator[](int);
	Vector3 operator+(Vector3& v1);
	Vector3 operator-(Vector3& v1);
	Vector3 operator*(Vector3& v1);
	Vector3 operator/(Vector3& v1);
};

