/* Type definitions */
#define BR_UINT unsigned int
#define BR_INT int
#define BR_FLOAT float
#define BR_DOUBLE double
#define BR_STRING char*

#define BR_PI 3.14159265359

/* Error definitions */
#ifndef BR_ERROR
	#include <iostream>
	#define BR_ERROR(x) std::cout << x << std::endl; 
#endif // !BR_ERROR