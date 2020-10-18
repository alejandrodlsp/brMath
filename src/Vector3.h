#pragma once

#include "../Typedefs.h"
#include "./Vector2.h"

namespace BreathEngine
{
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
		BR_FLOAT x, y, z;

		/* Constructors */
		Vector3(BR_FLOAT x, BR_FLOAT y, BR_FLOAT z);
		Vector3(Vector2 xy, BR_FLOAT z) : x(xy.x), y(xy.y), z(z) {};
		Vector3(BR_FLOAT x, Vector2 yz) : x(x), y(yz.x), z(yz.y) {};
		~Vector3();


		/* Public methods */
		const inline BR_FLOAT Magnitude();
		const inline Vector3 Normalized();
		const inline Vector3 SqrMagnitude();
		const BR_STRING str();

		/* Static methods */
		const static BR_FLOAT Angle(Vector3 from, Vector3 to);
		const static Vector3 Cross(Vector3 v1, Vector3 v2);
		const static BR_FLOAT Dot(Vector3 v1, Vector3 v2);
		const static BR_FLOAT Distance(Vector3 from, Vector3 to);

		const static Vector3 Lerp(Vector3 v1, Vector3 v2, BR_FLOAT factor);
		const static Vector3 LerpUnclamped(Vector3 v1, Vector3 v2, BR_FLOAT factor);
		const static Vector3 Max(Vector3 v1, Vector3 v2);
		const static Vector3 Min(Vector3 v1, Vector3 v2);
		// TODO: Move towards


		/* Operator overloading */
		BR_FLOAT operator[](BR_INT);
		Vector3 operator+(Vector3 v);
		Vector3 operator-(Vector3 v);
		Vector3 operator*(Vector3 v);
		Vector3 operator/(Vector3 v);

		Vector3 operator+(BR_FLOAT v);
		Vector3 operator-(BR_FLOAT v);
		Vector3 operator*(BR_FLOAT v);
		Vector3 operator/(BR_FLOAT v);
	};

};
