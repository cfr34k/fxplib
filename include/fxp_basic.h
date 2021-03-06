#ifndef FXP_BASIC_H
#define FXP_BASIC_H

#ifndef POINTPOS
	#warning POINTPOS is undefined, assuming 16.
	#define POINTPOS 16
#endif

#include <stdint.h>

typedef int32_t fxp_t;
typedef int64_t fxp_tmp_t;


/* some constants */
#if POINTPOS > 29
	#define FXP_CONSTSHIFT << (POINTPOS - 29)
#else
	#define FXP_CONSTSHIFT >> (29 - POINTPOS)
#endif

#define FXP_PI (0x6487ed51 FXP_CONSTSHIFT)
#define FXP_E (0x56fc2a2c FXP_CONSTSHIFT)


static inline fxp_t fxp_add(fxp_t a, fxp_t b)
{
	return a+b;
}

static inline fxp_t fxp_sub(fxp_t a, fxp_t b)
{
	return a-b;
}

static inline fxp_t fxp_mult(fxp_t a, fxp_t b)
{
	fxp_tmp_t tmp_val;

	tmp_val = (fxp_tmp_t)a * b;

	return (tmp_val >> POINTPOS);
}

static inline fxp_t fxp_div(fxp_t a, fxp_t b)
{
	fxp_tmp_t tmp_val;

	tmp_val = ((fxp_tmp_t)a << POINTPOS) / b;

	return tmp_val;
}

static inline fxp_t fxp_inv(fxp_t n)
{
	return ((fxp_tmp_t)1 << (2*POINTPOS)) / n;
}

static inline fxp_t fxp_abs(fxp_t n)
{
	if(n >= 0) {
		return n;
	} else {
		return -n;
	}
}

#endif // FXP_BASIC_H
