#include "../Typedefs.h"

namespace BreathEngine {
	static inline BR_FLOAT Abs(BR_FLOAT v);
	static inline BR_FLOAT Acos(BR_FLOAT v);
	static inline BR_FLOAT Approximately(BR_FLOAT v1, BR_FLOAT v2);
	static inline BR_FLOAT Asin(BR_FLOAT v);
	static inline BR_FLOAT Atan(BR_FLOAT v);
	static inline BR_FLOAT Atan2(BR_FLOAT v1, BR_FLOAT v2);
	static inline BR_FLOAT Ceil(BR_FLOAT v);
	static inline BR_FLOAT Clamp(BR_FLOAT v, BR_FLOAT min, BR_FLOAT max);
	static inline BR_FLOAT Clamp01(BR_FLOAT v);
	static inline BR_FLOAT Cos(BR_FLOAT v);
	static inline BR_FLOAT DeltaAngle(BR_FLOAT angle1, BR_FLOAT angle2);
	static inline BR_FLOAT Exp(BR_INT power);
	static inline BR_FLOAT Floor(BR_FLOAT v);
	static inline BR_FLOAT InverseLerp(BR_FLOAT v1, BR_FLOAT v2, BR_FLOAT t);
	static inline BR_FLOAT Lerp(BR_FLOAT v1, BR_FLOAT v2, BR_FLOAT t);
	static inline BR_FLOAT Log(BR_FLOAT v);
	static inline BR_FLOAT Log10(BR_FLOAT v);
	static inline BR_FLOAT Max(BR_FLOAT v1, BR_FLOAT v2);
	static inline BR_FLOAT Min(BR_FLOAT v1, BR_FLOAT v2);
	static inline BR_FLOAT MoveTowards(BR_FLOAT v, BR_FLOAT target, BR_FLOAT t);
	static inline BR_FLOAT Pow(BR_FLOAT v, BR_FLOAT pow);
	static inline BR_FLOAT Round(BR_FLOAT v);
	static inline BR_BOOLEAN Sign(BR_FLOAT v);
	static inline BR_FLOAT Sin(BR_FLOAT v);
	static inline BR_FLOAT Sqrt(BR_FLOAT v);
	static inline BR_FLOAT Tan(BR_FLOAT v);
	static inline BR_FLOAT Map(BR_FLOAT iMin, BR_FLOAT iMax, BR_FLOAT oMin, BR_FLOAT oMax, BR_FLOAT v);
}