#include "brMath.h"

int main()
{
	BR_FLOAT ls = BreathEngine::brMath::Lerp(0.0f, 10.0f, 0.5f);
	BR_ERROR(ls);
	while (true) continue;
}