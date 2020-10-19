#pragma once

#include "./Vector2.h"
#include "./Math.h"

namespace BreathEngine
{
	class Vector3
	{
	public:

		/* Static properties */
		static const Vector3 forward;
		static const Vector3 back;
		static const Vector3 up;
		static const Vector3 down;
		static const Vector3 left;
		static const Vector3 right;
		static const Vector3 one;
		static const Vector3 zero;

		/* Properties */
		BR_FLOAT x, y, z;

		/* Constructors */
		Vector3(BR_FLOAT x, BR_FLOAT y, BR_FLOAT z)
			: x(x), y(y), z(z)
		{
		}

		Vector3(Vector2 xy, BR_FLOAT z) : x(xy.x), y(xy.y), z(z) {};
		Vector3(BR_FLOAT x, Vector2 yz) : x(x), y(yz.x), z(yz.y) {};
		~Vector3()
		{
		}

		/* Public methods */
		const inline BR_FLOAT Magnitude()
		{
			return brMath::Sqrt(brMath::Pow(x, 2) + brMath::Pow(y, 2) + brMath::Pow(z, 2));
		}

		const inline Vector3 Normalized()
		{
			BR_FLOAT _mag = Magnitude();
			return Vector3(x / _mag, y / _mag, z / _mag);
		}

		const inline Vector3 SqrMagnitude()
		{
			Vector3 _norm = Normalized();
			return _norm * _norm;
		}

		const BR_STRING str() { return NULL;  }

		/* Static methods */
		const inline static BR_FLOAT Angle(Vector3 from, Vector3 to)
		{
			BR_FLOAT _dot = Dot(from.Normalized(), to.Normalized());
			_dot = (_dot < -1.0 ? -1.0 : (_dot > 1.0 ? 1.0 : _dot));
			return acos(_dot);
		}

		const inline static Vector3 Cross(Vector3 v1, Vector3 v2)
		{
			BR_FLOAT _x = v1.y * v2.z - v1.z * v2.y;
			BR_FLOAT _y = v1.z * v2.x - v1.x * v2.z;
			BR_FLOAT _z = v1.x * v2.y - v1.y * v2.x;
			return Vector3(_x, _y, _z);
		}

		const inline static BR_FLOAT Dot(Vector3 v1, Vector3 v2)
		{
			BR_FLOAT _product = 0;
			for (int i = 0; i < 3; i++)
				_product = _product + v1[i] * v2[i];
			return _product;
		}

		const inline static BR_FLOAT Distance(Vector3 from, Vector3 to)
		{
			return sqrt(pow(to.x - from.x, 2) + pow(to.y = from.y, 2) + pow(to.z - from.z, 2));
		}

		const inline static Vector3 Lerp(Vector3 v1, Vector3 v2, BR_FLOAT factor)
		{
			BR_FLOAT clampedFactor = brMath::Clamp01(factor);
			return v1 + ((v2 - v1) / clampedFactor);
		}

		const inline static Vector3 LerpUnclamped(Vector3 v1, Vector3 v2, BR_FLOAT factor)
		{
			return v1 + ((v2 - v1) / factor);
		}

		const inline static Vector3 Max(Vector3 v1, Vector3 v2)
		{
			return Vector3(brMath::Max(v1.x, v2.x), brMath::Max(v1.y, v2.y), brMath::Max(v1.z, v2.z));
		}

		const inline static Vector3 Min(Vector3 v1, Vector3 v2)
		{
			return Vector3(brMath::Min(v1.x, v2.x), brMath::Min(v1.y, v2.y), brMath::Min(v1.z, v2.z));
		}

		const static Vector3 MoveTowards(Vector3 v1, Vector3 v2, BR_FLOAT factor)
		{
			return Vector3(
					brMath::Clamp(v1.x + factor, v1.x, v2.x), 
					brMath::Clamp(v1.y + factor, v1.y, v2.y), 
					brMath::Clamp(v1.z + factor, v1.z, v2.z)
			);
		}

		/* Operator overloading */
		BR_FLOAT operator[](BR_INT pos)
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

		Vector3 operator+(Vector3 v1)
		{
			return Vector3(x + v1.x, y + v1.y, z + v1.z);
		}

		Vector3 operator-(Vector3 v1)
		{
			return Vector3(x - v1.x, y - v1.y, z - v1.z);
		}

		Vector3 operator*(Vector3 v1)
		{
			return Vector3(x * v1.x, y * v1.y, z * v1.z);
		}

		Vector3 operator/(Vector3 v1)
		{
			return Vector3(x / v1.x, y / v1.y, z / v1.z);
		}

		Vector3 operator+(BR_FLOAT v1)
		{
			return Vector3(x + v1, y + v1, z + v1);
		}

		Vector3 operator-(BR_FLOAT v1)
		{
			return Vector3(x - v1, y - v1, z - v1);
		}

		Vector3 operator*(BR_FLOAT v1)
		{
			return Vector3(x * v1, y * v1, z * v1);
		}

		Vector3 operator/(BR_FLOAT v1)
		{
			return Vector3(x / v1, y / v1, z / v1);
		}

		BR_BOOLEAN operator==(Vector3 v1)
		{
			return (brMath::Approximately(x, v1.x) && brMath::Approximately(y, v1.y) && brMath::Approximately(z, v1.z));
		}
	};

	/* Constants declaration */
	const Vector3 Vector3::forward = Vector3(0.0, 0.0, 1.0);
	const Vector3 Vector3::back = Vector3(0.0, 0.0, -1.0);
	const Vector3 Vector3::up = Vector3(0.0, 1.0, 0.0);
	const Vector3 Vector3::down = Vector3(0.0, -1.0, 0.0);
	const Vector3 Vector3::left = Vector3(-1.0, 0.0, 0.0);
	const Vector3 Vector3::right = Vector3(1.0, 0.0, 0.0);
	const Vector3 Vector3::one = Vector3(1.0, 1.0, 1.0);
	const Vector3 Vector3::zero = Vector3(0.0, 0.0, 0.0);

};
