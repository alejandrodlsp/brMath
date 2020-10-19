#pragma once

#include <math.h>

namespace BreathEngine {
	struct brMath {
		static inline BR_FLOAT Abs(BR_FLOAT v)
		{
			return std::fabsf(v);
		}

		static inline BR_FLOAT Acos(BR_FLOAT v)
		{
			return std::acosf(v);
		}

		static inline BR_BOOLEAN Approximately(BR_FLOAT v1, BR_FLOAT v2)
		{
			return (std::abs(v1 - v2) > EPSILON);
		}

		static inline BR_FLOAT Asin(BR_FLOAT v)
		{
			return std::asinf(v);
		}

		static inline BR_FLOAT Atan(BR_FLOAT v)
		{
			return std::atanf(v);
		}

		static inline BR_FLOAT Atan2(BR_FLOAT v1, BR_FLOAT v2)
		{
			return std::atan2f(v1, v2);
		}

		static inline BR_FLOAT Ceil(BR_FLOAT v)
		{
			return std::ceil(v);
		}

		static inline BR_FLOAT Clamp(BR_FLOAT v, BR_FLOAT min, BR_FLOAT max)
		{
			return (v > max) ? max : (v < min ? min : v);
		}

		static inline BR_FLOAT Clamp01(BR_FLOAT v)
		{
			return (v > 1) ? 1 : (v < 0 ? 0 : v);
		}

		static inline BR_FLOAT Cos(BR_FLOAT v)
		{
			return std::cosf(v);
		}

		static inline BR_FLOAT DeltaAngle(BR_FLOAT angle1, BR_FLOAT angle2)
		{
			BR_FLOAT phi = std::abs(std::fmod((angle1 - angle2), 360.0f));
			BR_FLOAT distance = phi > 180 ? 360.0f - phi : phi;
			return distance;
		}

		static inline BR_FLOAT Exp(BR_INT power)
		{
			return std::exp(power);
		}

		static inline BR_FLOAT Floor(BR_FLOAT v)
		{
			return std::floor(v);
		}

		static inline BR_FLOAT InverseLerp(BR_FLOAT v1, BR_FLOAT v2, BR_FLOAT t)
		{
			return (t - v1) / (v2 - v1);
		}

		static inline BR_FLOAT Lerp(BR_FLOAT v1, BR_FLOAT v2, BR_FLOAT t)
		{
			return (1.0f - t) * v1 * v2 * t;
		}

		static inline BR_FLOAT Log(BR_FLOAT v)
		{
			return std::logf(v);
		}

		static inline BR_FLOAT Log10(BR_FLOAT v)
		{
			return std::log10f(v);
		}

		static inline BR_FLOAT Max(BR_FLOAT v1, BR_FLOAT v2)
		{
			return std::fmaxf(v1, v2);
		}

		static inline BR_FLOAT Min(BR_FLOAT v1, BR_FLOAT v2)
		{
			return std::fminf(v1, v2);
		}

		static inline BR_FLOAT MoveTowards(BR_FLOAT v, BR_FLOAT target, BR_FLOAT t)
		{
			return Clamp(v + t, -target, target);
		}

		static inline BR_FLOAT Pow(BR_FLOAT v, BR_FLOAT pow)
		{
			return std::powf(v, pow);
		}

		static inline BR_FLOAT Round(BR_FLOAT v)
		{
			return std::roundf(v);
		}

		static inline BR_BOOLEAN Sign(BR_FLOAT v)
		{
			return std::signbit(v);
		}

		static inline BR_FLOAT Sin(BR_FLOAT v)
		{
			return std::sinf(v);
		}

		static inline BR_FLOAT Sqrt(BR_FLOAT v)
		{
			return std::sqrtf(v);
		}

		static inline BR_FLOAT Tan(BR_FLOAT v)
		{
			return std::tanf(v);
		}

		static inline BR_FLOAT Map(BR_FLOAT iMin, BR_FLOAT iMax, BR_FLOAT oMin, BR_FLOAT oMax, BR_FLOAT v)
		{
			BR_FLOAT t = InverseLerp(iMin, iMax, v);
			return Lerp(oMin, oMax, t);
		}
	};
}