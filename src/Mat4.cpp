#include "Mat4.h"

using namespace BreathEngine;

/* Static properties */
/* Properties */

/* Constructors */
Mat4::Mat4()
{
	memset(&this->mElements, 0, sizeof(this->mElements));
	this->mElements[0] = 1;
	this->mElements[5] = 1;
	this->mElements[10] = 1;
	this->mElements[15] = 1;
}

Mat4::Mat4(BR_FLOAT elements[])
{
	memset(&this->mElements, 0, sizeof(this->mElements));
	for (int i = 0; i < 16; i++)
	{
		this->mElements[i] = elements[i];
	}
}

Mat4::~Mat4()
{
}

/* Public methods */
BR_FLOAT* Mat4::GetElementsPointer()
{
	return this->mElements;
}

/* Static methods*/

Mat4 Mat4::Scale(Vector3 scale)
{
	Mat4 newMatrix = Mat4();
	newMatrix.mElements[0] = scale.x;
	newMatrix.mElements[5] = scale.y;
	newMatrix.mElements[10] = scale.z;
	return newMatrix;
}

Mat4 Mat4::Translate(Vector3 translation)
{
	Mat4 newMatrix = Mat4();
	newMatrix.mElements[3] = translation.x;
	newMatrix.mElements[7] = translation.y;
	newMatrix.mElements[11] = translation.z;
	return newMatrix;
}

Mat4 Mat4::RotationX(BR_FLOAT angle)
{
	Mat4 newMatrix = Mat4();
	newMatrix.mElements[5] = std::cos(-angle);
	newMatrix.mElements[6] = -std::sin(-angle);
	newMatrix.mElements[9] = std::sin(-angle);
	newMatrix.mElements[10] = std::cos(-angle);
	return newMatrix;
}

Mat4 Mat4::RotationY(BR_FLOAT angle)
{
	Mat4 newMatrix = Mat4();
	newMatrix.mElements[0] = std::cos(-angle);
	newMatrix.mElements[2] = std::sin(-angle);
	newMatrix.mElements[8] = -std::sin(-angle);
	newMatrix.mElements[10] = std::cos(-angle);
	return newMatrix;
}

Mat4 Mat4::RotationZ(BR_FLOAT angle)
{
	Mat4 newMatrix = Mat4();
	newMatrix.mElements[0] = std::cos(-angle);
	newMatrix.mElements[1] = -std::sin(-angle);
	newMatrix.mElements[4] = std::sin(-angle);
	newMatrix.mElements[5] = std::cos(-angle);
	return newMatrix;
}

Mat4 Mat4::CreateView(Vector3 forward, Vector3 up, Vector3 right, Vector3 position)
{
	Mat4 newMatrixOne = Mat4();
	newMatrixOne.mElements[0] = right.x;
	newMatrixOne.mElements[1] = right.y;
	newMatrixOne.mElements[2] = right.z;
	newMatrixOne.mElements[4] = up.x;
	newMatrixOne.mElements[5] = up.y;
	newMatrixOne.mElements[6] = up.z;
	newMatrixOne.mElements[8] = forward.x;
	newMatrixOne.mElements[9] = forward.y;
	newMatrixOne.mElements[10] = forward.z;

	Mat4 newMatrixTwo = Mat4();
	newMatrixTwo.mElements[3] = -position.x;
	newMatrixTwo.mElements[7] = -position.y;
	newMatrixTwo.mElements[11] = -position.z;

	Mat4 newMatrix = newMatrixOne * newMatrixTwo;
	return newMatrix;
}

Mat4 Mat4::CreatePerspectiveProjection(BR_FLOAT width, BR_FLOAT height, BR_FLOAT fov, BR_FLOAT nearPlane, BR_FLOAT farPlane)
{
	Mat4 newMatrix = Mat4();
	newMatrix.mElements[0] = (1.0f / std::tan((fov * BR_PI / 180.0f) / 2.0f)) / (width / height);
	newMatrix.mElements[5] = 1.0f / std::tan((fov * BR_PI / 180.0f) / 2.0f);
	newMatrix.mElements[10] = (farPlane + nearPlane) / (nearPlane - farPlane);
	newMatrix.mElements[11] = (2.0f * farPlane * nearPlane) / (nearPlane - farPlane);
	newMatrix.mElements[14] = -1.0f;
	return newMatrix;
}

Mat4 Mat4::CreateOrthographicProjection(BR_FLOAT left, BR_FLOAT right, BR_FLOAT top, BR_FLOAT bottom, BR_FLOAT farPlane, BR_FLOAT nearPlane)
{
	Mat4 newMatrix = Mat4();
	newMatrix.mElements[0] = 2.0f / (right - left);
	newMatrix.mElements[3] = -((right + left) / (right - left));
	newMatrix.mElements[5] = 2.0f / (top - bottom);
	newMatrix.mElements[7] = -((top + bottom) / (top - bottom));
	newMatrix.mElements[10] = 2.0f / (farPlane - nearPlane);
	newMatrix.mElements[11] = -((farPlane + nearPlane) / (farPlane - nearPlane));
	return newMatrix;
}

/* Operator Overloading */


inline Mat4& Mat4::operator+=(const Mat4& rhs)
{
	for (int i = 0; i < 16; i++)
	{
		this->mElements[i] += rhs.mElements[i];
	}
	return *this;
}

inline Mat4& Mat4::operator-=(const Mat4& rhs)
{
	for (int i = 0; i < 16; i++)
	{
		this->mElements[i] -= rhs.mElements[i];
	}
	return *this;
}

inline Mat4& Mat4::operator*=(const Mat4& rhs)
{
	this->mElements[0] = this->mElements[0] * rhs.mElements[0] + this->mElements[1] * rhs.mElements[4] + this->mElements[2] * rhs.mElements[8] + this->mElements[3] * rhs.mElements[12];
	this->mElements[1] = this->mElements[0] * rhs.mElements[1] + this->mElements[1] * rhs.mElements[5] + this->mElements[2] * rhs.mElements[9] + this->mElements[3] * rhs.mElements[13];
	this->mElements[2] = this->mElements[0] * rhs.mElements[2] + this->mElements[1] * rhs.mElements[6] + this->mElements[2] * rhs.mElements[10] + this->mElements[3] * rhs.mElements[14];
	this->mElements[3] = this->mElements[0] * rhs.mElements[3] + this->mElements[1] * rhs.mElements[7] + this->mElements[2] * rhs.mElements[11] + this->mElements[3] * rhs.mElements[15];

	this->mElements[4] = this->mElements[4] * rhs.mElements[0] + this->mElements[5] * rhs.mElements[4] + this->mElements[6] * rhs.mElements[8] + this->mElements[7] * rhs.mElements[12];
	this->mElements[5] = this->mElements[4] * rhs.mElements[1] + this->mElements[5] * rhs.mElements[5] + this->mElements[6] * rhs.mElements[9] + this->mElements[7] * rhs.mElements[13];
	this->mElements[6] = this->mElements[4] * rhs.mElements[2] + this->mElements[5] * rhs.mElements[6] + this->mElements[6] * rhs.mElements[10] + this->mElements[7] * rhs.mElements[14];
	this->mElements[7] = this->mElements[4] * rhs.mElements[3] + this->mElements[5] * rhs.mElements[7] + this->mElements[6] * rhs.mElements[11] + this->mElements[7] * rhs.mElements[15];

	this->mElements[8] = this->mElements[8] * rhs.mElements[0] + this->mElements[9] * rhs.mElements[4] + this->mElements[10] * rhs.mElements[8] + this->mElements[11] * rhs.mElements[12];
	this->mElements[9] = this->mElements[8] * rhs.mElements[1] + this->mElements[9] * rhs.mElements[5] + this->mElements[10] * rhs.mElements[9] + this->mElements[11] * rhs.mElements[13];
	this->mElements[10] = this->mElements[8] * rhs.mElements[2] + this->mElements[9] * rhs.mElements[6] + this->mElements[10] * rhs.mElements[10] + this->mElements[11] * rhs.mElements[14];
	this->mElements[11] = this->mElements[8] * rhs.mElements[3] + this->mElements[9] * rhs.mElements[7] + this->mElements[10] * rhs.mElements[11] + this->mElements[11] * rhs.mElements[15];

	this->mElements[12] = this->mElements[12] * rhs.mElements[0] + this->mElements[13] * rhs.mElements[4] + this->mElements[14] * rhs.mElements[8] + this->mElements[15] * rhs.mElements[12];
	this->mElements[13] = this->mElements[12] * rhs.mElements[1] + this->mElements[13] * rhs.mElements[5] + this->mElements[14] * rhs.mElements[9] + this->mElements[15] * rhs.mElements[13];
	this->mElements[14] = this->mElements[12] * rhs.mElements[2] + this->mElements[13] * rhs.mElements[6] + this->mElements[14] * rhs.mElements[10] + this->mElements[15] * rhs.mElements[14];
	this->mElements[15] = this->mElements[12] * rhs.mElements[3] + this->mElements[13] * rhs.mElements[7] + this->mElements[14] * rhs.mElements[11] + this->mElements[15] * rhs.mElements[15];
	return *this;
}

inline Mat4& Mat4::operator*=(const BR_FLOAT& rhs)
{
	for (int i = 0; i < 16; i++)
	{
		this->mElements[i] *= rhs;
	}
	return *this;
}


inline Mat4 Mat4::operator+(const Mat4& rhs)
{
	Mat4 newMatrix = Mat4(this->mElements);
	newMatrix += rhs;
	return newMatrix;
}

inline Mat4 Mat4::operator-(const Mat4& rhs)
{
	Mat4 newMatrix = Mat4(this->mElements);
	newMatrix -= rhs;
	return newMatrix;
}

inline Mat4 Mat4::operator*(const Mat4& rhs)
{
	Mat4 newMatrix = Mat4(this->mElements);
	newMatrix *= rhs;
	return newMatrix;
}

inline Mat4 Mat4::operator*(const BR_FLOAT& rhs)
{
	Mat4 newMatrix = Mat4(this->mElements);
	newMatrix *= rhs;
	return newMatrix;
}