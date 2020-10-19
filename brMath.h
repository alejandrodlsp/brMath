#pragma once

/* Type definitions */
#define BR_UINT unsigned int
#define BR_INT int
#define BR_FLOAT float
#define BR_DOUBLE double
#define BR_STRING char*
#define BR_BOOLEAN bool

/* Constants definitions*/
#define PI 3.14159265358979f
#define Rad2Deg (360 / (3.14159265358979f * 2))
#define Deg2Rad ((3.14159265358979f * 2) / 360)
#define Infinity INFINITY
#define NegativeInfinity -INFINITY
#define EPSILON 0.00001f

/* Error definitions */
#ifndef BR_ERROR
#include <iostream>
#define BR_ERROR(x) std::cout << x << std::endl; 
#endif // !BR_ERROR

/* Exports */
#include "src/Vector3.h"
#include "src/Mat4.h"
#include "src/Math.h"






