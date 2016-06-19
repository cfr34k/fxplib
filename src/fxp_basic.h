#ifndef FXP_BASIC_H
#define FXP_BASIC_H

#include "fxp.h"

inline fxp_t fxp_from_float(float v)
{
	return v * (1 << POINTPOS);
}

inline fxp_t fxp_from_int(int32_t v)
{
	return v << POINTPOS;
}

inline float fxp_to_float(fxp_t v)
{
	return (float)v / (1 << POINTPOS);
}

inline fxp_t fxp_add(fxp_t a, fxp_t b)
{
	return a+b;
}

inline fxp_t fxp_sub(fxp_t a, fxp_t b)
{
	return a-b;
}

inline fxp_t fxp_mult(fxp_t a, fxp_t b)
{
	fxp_tmp_t tmp_val;

	tmp_val = (fxp_tmp_t)a * b;

	return (tmp_val >> POINTPOS);
}

inline fxp_t fxp_div(fxp_t a, fxp_t b)
{
	fxp_tmp_t tmp_val;

	tmp_val = ((fxp_tmp_t)a << POINTPOS) / b;

	return tmp_val;
}

#endif // FXP_BASIC_H
