#pragma once

#include "Math.h"

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
		Vector2(BR_FLOAT x, BR_FLOAT y)
			: x(x), y(y)
		{
		}
		~Vector2() 
		{
		}

		/* Public methods */
		const inline BR_FLOAT Magnitude()
		{
			return brMath::Sqrt(brMath::Pow(x, 2) + brMath::Pow(y, 2));
		}

		const inline Vector2 Normalized()
		{
			BR_FLOAT _mag = Magnitude();
			return Vector2(x / _mag, y / _mag);
		}

		const inline Vector2 SqrMagnitude()
		{
			Vector2 _norm = Normalized();
			return _norm * _norm;
		}

		const BR_STRING str() { return NULL; }

		/* Static methods */
		const static BR_FLOAT Angle(Vector2 from, Vector2 to)
		{
			BR_FLOAT _dot = Dot(from.Normalized(), to.Normalized());
			_dot = (_dot < -1.0 ? -1.0 : (_dot > 1.0 ? 1.0 : _dot));
			return acos(_dot);
		}

		const static BR_FLOAT Cross(Vector2 v1, Vector2 v2)
		{
			return v1.x * v2.y - v1.y * v2.x;
		}

		const static BR_FLOAT Dot(Vector2 v1, Vector2 v2)
		{
			return v1.x * v2.x + v1.y + v2.y;
		}

		const static BR_FLOAT Distance(Vector2 from, Vector2 to)
		{
			return sqrt(pow(to.x - from.x, 2) + pow(to.y = from.y, 2));
		}

		const static Vector2 Lerp(Vector2 v1, Vector2 v2, BR_FLOAT factor)
		{
			BR_FLOAT clampedFactor = brMath::Clamp01(factor);
			return v1 + ((v2 - v1) / clampedFactor);
		}

		const static Vector2 LerpUnclamped(Vector2 v1, Vector2 v2, BR_FLOAT factor)
		{
			return v1 + ((v2 - v1) / factor);
		}

		const static Vector2 Max(Vector2 v1, Vector2 v2)
		{
			return Vector2(brMath::Max(v1.x, v2.x), brMath::Max(v1.y, v2.y));
		}

		const static Vector2 Min(Vector2 v1, Vector2 v2)
		{
			return Vector2(brMath::Min(v1.x, v2.x), brMath::Min(v1.y, v2.y));
		}

		const static Vector2 MoveTowards(Vector2 v1, Vector2 v2, BR_FLOAT factor)
		{
			return Vector2( brMath::Clamp(v1.x + factor, v1.x, v2.x), brMath::Clamp(v1.y + factor, v1.y, v2.y));
		}

		/* Operator overloading */
		BR_FLOAT operator[](BR_INT pos)
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

		Vector2 operator+(Vector2 v1)
		{
			return Vector2(x + v1.x, y + v1.y);
		}

		Vector2 operator-(Vector2 v1)
		{
			return Vector2(x - v1.x, y - v1.y);
		}

		Vector2 operator*(Vector2 v1)
		{
			return Vector2(x * v1.x, y * v1.y);
		}

		Vector2 operator/(Vector2 v1)
		{
			return Vector2(x / v1.x, y / v1.y);
		}

		Vector2 operator+(BR_FLOAT v1)
		{
			return Vector2(x + v1, y + v1);
		}

		Vector2 operator-(BR_FLOAT v1)
		{
			return Vector2(x - v1, y - v1);
		}

		Vector2 operator*(BR_FLOAT v1)
		{
			return Vector2(x * v1, y * v1);
		}

		Vector2 operator/(BR_FLOAT v1)
		{
			return Vector2(x / v1, y / v1);
		}

		BR_BOOLEAN operator==(Vector2 v1)
		{
			return (brMath::Approximately(x, v1.x) && brMath::Approximately(y, v1.y));
		}
	};

	/* Constants declaration */
	const Vector2 Vector2::up = Vector2(0.0, 1.0);
	const Vector2 Vector2::down = Vector2(0.0, -1.0);
	const Vector2 Vector2::left = Vector2(-1.0, 0.0);
	const Vector2 Vector2::right = Vector2(1.0, 0.0);
	const Vector2 Vector2::one = Vector2(1.0, 1.0);
	const Vector2 Vector2::zero = Vector2(0.0, 0.0);
};
