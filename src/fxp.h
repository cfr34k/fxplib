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
#define FXP_STR_MAXLEN 12 // 10 digits + sign + decimal point

/*!
 * Formats the given integer into str.
 *
 * \param n      The integer to format.
 * \param str    The string to write the result to.
 * \returns      The number of characters written.
 */
int fxp_format_int(int32_t n, char *str);

/*!
 * Formats the given fixed point number into str.
 *
 * \param n            The number to format.
 * \param str          The string to write the result to.
 * \param frac_digits  Number of fractional digits to display.
 * \returns            The number of characters written.
 */
int fxp_format(int32_t n, char *str, unsigned int frac_digits);

#endif // FXP_H
