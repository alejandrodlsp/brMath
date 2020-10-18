#pragma once

#include "../Typedefs.h"

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
		// TODO: [0], [1], [2] postional accessors

		/* Constructors */
		Vector3(BR_FLOAT x, BR_FLOAT y, BR_FLOAT z);
		// TODO: Vector2 based constructors
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

		// TODO: Lerp
		// TODO: Lerp unclamped
		const static Vector3 Max(Vector3 v1, Vector3 v2);
		const static Vector3 Min(Vector3 v1, Vector3 v2);
		// TODO: Move towards


		/* Operator overloading */
		BR_FLOAT operator[](BR_INT);
		Vector3 operator+(Vector3& v1);
		Vector3 operator-(Vector3& v1);
		Vector3 operator*(Vector3& v1);
		Vector3 operator/(Vector3& v1);
	};

};
