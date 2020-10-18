#include "brMath.h"

int main()
{
	BR_FLOAT ls = BreathEngine::InverseLerp(0.0f, 10.0f, 5.0f);
	BR_ERROR(ls);
	while (true) continue;
}