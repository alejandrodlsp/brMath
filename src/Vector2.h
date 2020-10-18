#pragma once

#include "../Typedefs.h"

namespace BreathEngine
{
	class Vector2
	{
	public:
		/* Static properties */
		const static Vector2 up;
		const static Vector2 down;
		const static Vector2 left;
		const static Vector2 right;
		const static Vector2 one;
		const static Vector2 zero;

		/* Properties */
		BR_FLOAT x, y;

		/* Constructors */
		Vector2(BR_FLOAT x, BR_FLOAT y);
		// TODO: Vector2 based constructors
		~Vector2();


		/* Public methods */
		const inline BR_FLOAT Magnitude();
		const inline Vector2 Normalized();
		const inline Vector2 SqrMagnitude();
		const BR_STRING str();

		/* Static methods */
		const static BR_FLOAT Angle(Vector2 from, Vector2 to);
		const static BR_FLOAT Cross(Vector2 v1, Vector2 v2);
		const static BR_FLOAT Dot(Vector2 v1, Vector2 v2);
		const static BR_FLOAT Distance(Vector2 from, Vector2 to);

		const static Vector2 Lerp(Vector2 v1, Vector2 v2, BR_FLOAT factor);
		const static Vector2 LerpUnclamped(Vector2 v1, Vector2 v2, BR_FLOAT factor);
		const static Vector2 Max(Vector2 v1, Vector2 v2);
		const static Vector2 Min(Vector2 v1, Vector2 v2);
		// TODO: Move towards


		/* Operator overloading */
		BR_FLOAT operator[](BR_INT);
		Vector2 operator+(Vector2 v);
		Vector2 operator-(Vector2 v);
		Vector2 operator*(Vector2 v);
		Vector2 operator/(Vector2 v);

		Vector2 operator+(BR_FLOAT v);
		Vector2 operator-(BR_FLOAT v);
		Vector2 operator*(BR_FLOAT v);
		Vector2 operator/(BR_FLOAT v);
	};

};
