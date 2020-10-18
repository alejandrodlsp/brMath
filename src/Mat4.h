#pragma once

#include "../Typedefs.h"
#include "Vector3.h"

namespace BreathEngine
{
	class Mat4
	{
	public:
		/* Static Properties */
		/* Properties */
		BR_FLOAT mElements[16];

		/* Constructors */
		Mat4();
		Mat4(BR_FLOAT elements[]);
		~Mat4();

		/* Public methods */
		BR_FLOAT* GetElementsPointer();

		/* Static methods */
		static Mat4 Scale(Vector3 scale);
		static Mat4 Translate(Vector3 translation);
		static Mat4 RotationX(BR_FLOAT angle);
		static Mat4 RotationY(BR_FLOAT angle);
		static Mat4 RotationZ(BR_FLOAT angle);
		static Mat4 CreateView(Vector3 forward, Vector3 up, Vector3 right, Vector3 position);
		static Mat4 CreatePerspectiveProjection(BR_FLOAT width, BR_FLOAT height, BR_FLOAT fov, BR_FLOAT nearPlane, BR_FLOAT farPlane);
		static Mat4 CreateOrthographicProjection(BR_FLOAT left, BR_FLOAT right, BR_FLOAT top, BR_FLOAT bottom, BR_FLOAT farPlane, BR_FLOAT nearPlane);

		/* Operator overloading */
		inline Mat4& operator+=(const Mat4& rhs);
		inline Mat4& operator-=(const Mat4& rhs);
		inline Mat4& operator*=(const Mat4& rhs);
		inline Mat4& operator*=(const BR_FLOAT& rhs);

		inline Mat4 operator+(const Mat4& rhs);
		inline Mat4 operator-(const Mat4& rhs);
		inline Mat4 operator*(const Mat4& rhs);
		inline Mat4 operator*(const BR_FLOAT& rhs);
	};


};
