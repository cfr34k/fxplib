#ifndef FXP_H
#define FXP_H

#include <fxp_basic.h>

/*
 * IMPORTANT:
 *
 * FXP basic arithmetic is implemented in fxp_basic.h, which allows these
 * functions to be inlined.
 */

/*
 * FXP conversion macros
 */
#define FXP_FROM_INT(x) ((x >= 0) ? ((fxp_t)(x) << POINTPOS) : (-((fxp_t)(-x) << POINTPOS)))
#define FXP_TO_INT(x)   ((int32_t)((x) >> POINTPOS))

/*
 * FXP conversion functions
 */
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

/*!
 * Generate a output string which contains the input string right-aligned,
 * prefixed with the fill characters.
 *
 * \param in          The input string.
 * \param out         The output string (must be at least width+1 characters long).
 * \param width       Width of the output.
 * \param fill        The fill character.
 */
void fxp_right_align(char *in, char *out, unsigned int width, char fill);

#endif // FXP_H
