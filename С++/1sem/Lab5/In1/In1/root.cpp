#include "root.h"

float root(float a, float b)
{
		float res;
		if (a != 0) res = -b / a;
		else res = 0;
		return res;
}
