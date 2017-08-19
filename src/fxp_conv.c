#include "fxp.h"

fxp_t fxp_from_float(float v)
{
	return v * (1 << POINTPOS);
}

float fxp_to_float(fxp_t v)
{
	return (float)v / (1 << POINTPOS);
}

