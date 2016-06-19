#ifndef FXP_H
#define FXP_H

#ifndef POINTPOS
	#define POINTPOS 16
#endif

#include <stdint.h>

typedef int32_t fxp_t;
typedef int64_t fxp_tmp_t;

/*
 * IMPORTANT:
 *
 * FXP basic arithmetic is implemented in fxp_basic.h, which allows these
 * functions to be inlined.
 */

/*
 * FXP conversion functions
 */
fxp_t fxp_from_int(int32_t v);

fxp_t fxp_from_float(float v);
float fxp_to_float(fxp_t v);

/*
 * FXP to string conversions
 */
void fxp_format_int(int32_t n, char *str);

#endif // FXP_H
