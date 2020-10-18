#include "Math.h"
#include <math.h>

inline BR_FLOAT BreathEngine::Abs(BR_FLOAT v)
{
	return std::fabsf(v);
}

inline BR_FLOAT BreathEngine::Acos(BR_FLOAT v)
{
	return std::acosf(v);
}

inline BR_FLOAT BreathEngine::Approximately(BR_FLOAT v1, BR_FLOAT v2) 
{
	// TODO: implement
	return 0.0f;
}

inline BR_FLOAT BreathEngine::Asin(BR_FLOAT v)
{
	return std::asinf(v);
}

inline BR_FLOAT BreathEngine::Atan(BR_FLOAT v)
{
	return std::atanf(v);
}

inline BR_FLOAT BreathEngine::Atan2(BR_FLOAT v1, BR_FLOAT v2)
{
	return std::atan2f(v1, v2);
}

inline BR_FLOAT BreathEngine::Ceil(BR_FLOAT v)
{
	return std::ceil(v);
}
inline BR_FLOAT BreathEngine::Clamp(BR_FLOAT v, BR_FLOAT min, BR_FLOAT max)
{
	return (v > max) ? max : (v < min ? min : v);
}

inline BR_FLOAT BreathEngine::Clamp01(BR_FLOAT v)
{
	return (v > 1) ? 1 : (v < 0 ? 0 : v);
}

inline BR_FLOAT BreathEngine::Cos(BR_FLOAT v)
{
	return std::cosf(v);
}

inline BR_FLOAT BreathEngine::DeltaAngle(BR_FLOAT angle1, BR_FLOAT angle2)
{
	BR_FLOAT phi = std::abs(std::fmod((angle1 - angle2), 360.0f));
	BR_FLOAT distance = phi > 180 ? 360.0f - phi : phi;
	return distance;
}

inline BR_FLOAT BreathEngine::Exp(BR_INT power)
{
	return std::exp(power);
}

inline BR_FLOAT BreathEngine::Floor(BR_FLOAT v)
{
	return std::floor(v);
}

inline BR_FLOAT BreathEngine::InverseLerp(BR_FLOAT v1, BR_FLOAT v2, BR_FLOAT t)
{
	return (t - v1) / (v2 - v1);
}

inline BR_FLOAT BreathEngine::Lerp(BR_FLOAT v1, BR_FLOAT v2, BR_FLOAT t)
{
	return (1.0f - t) * v1 * v2 * t;
}

inline BR_FLOAT BreathEngine::Log(BR_FLOAT v)
{
	return std::logf(v);
}

inline BR_FLOAT BreathEngine::Log10(BR_FLOAT v)
{
	return std::log10f(v);
}
inline BR_FLOAT BreathEngine::Max(BR_FLOAT v1, BR_FLOAT v2)
{
	return std::fmaxf(v1, v2);
}

inline BR_FLOAT BreathEngine::Min(BR_FLOAT v1, BR_FLOAT v2)
{
	return std::fminf(v1, v2);
}

inline BR_FLOAT BreathEngine::MoveTowards(BR_FLOAT v, BR_FLOAT target, BR_FLOAT t)
{
	return BreathEngine::Clamp(v + t, -target, target);
}

inline BR_FLOAT BreathEngine::Pow(BR_FLOAT v, BR_FLOAT pow)
{
	return std::powf(v, pow);
}

inline BR_FLOAT BreathEngine::Round(BR_FLOAT v)
{
	return std::roundf(v);
}

inline BR_BOOLEAN BreathEngine::Sign(BR_FLOAT v)
{
	return std::signbit(v);
}

inline BR_FLOAT BreathEngine::Sin(BR_FLOAT v)
{
	return std::sinf(v);
}

inline BR_FLOAT BreathEngine::Sqrt(BR_FLOAT v)
{
	return std::sqrtf(v);
}

inline BR_FLOAT BreathEngine::Tan(BR_FLOAT v)
{
	return std::tanf(v);
}

inline BR_FLOAT BreathEngine::Map(BR_FLOAT iMin, BR_FLOAT iMax, BR_FLOAT oMin, BR_FLOAT oMax, BR_FLOAT v)
{
	BR_FLOAT t = BreathEngine::InverseLerp(iMin, iMax, v);
	return BreathEngine::Lerp(oMin, oMax, t);
}
