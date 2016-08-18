#include "fxp.h"

int fxp_format_int(int32_t n, char *str)
{
	int ndigits;
	int32_t tmp;
	char *ptr;

	if(n == 0) {
		str[0] = '0';
		str[1] = '\0';
		return 1;
	}

	// calculate number of digits
	if(n < 0) {
		ndigits = 1;
		tmp = -n;
	} else {
		ndigits = 0;
		tmp = n;
	}

	while(tmp != 0) {
		tmp /= 10;
		ndigits++;
	}

	if(n < 0) {
		str[0] = '-';
		tmp = -n;
	} else {
		tmp = n;
	}

	ptr = str + ndigits - 1;

	while(tmp != 0) {
		*ptr = '0' + (tmp % 10);

		tmp /= 10;
		ptr--;
	}

	str[ndigits] = '\0';

	return ndigits;
}

int fxp_format(fxp_t v, char *str, unsigned int frac_digits)
{
	unsigned int ndigits = 0, digits_written = 0;
	int32_t v_scaled, tmp;
	fxp_t factor;
	char *ptr;

	// scale the input value to make it processible
	factor = 1;
	for(unsigned int i = 0; i < frac_digits; i++) {
		factor *= 10;
	}

	v_scaled = (int32_t)(((fxp_tmp_t)v * factor + (1 << (POINTPOS-1))) >> POINTPOS);
	//                                Rounding -^

	// handle 0 value
	if(v_scaled == 0) {
		*(str++) = '0';
		if(frac_digits > 0) {
			*(str++) = '.';
			for(unsigned int i = 0; i < frac_digits; i++) {
				*(str++) = '0';
			}
		}
		*str = '\0';
		if(frac_digits > 0) {
			return 2 + frac_digits;
		} else {
			return 1;
		}
	}

	// handle sign: set '-' as first character and invert sign. Now remaining
	// processing is identical for positive and negative numbers.
	if(v_scaled < 0) {
		v_scaled = -v_scaled;
		*(str++) = '-';
	}

	// calculate number of digits.
	tmp = v_scaled;

	// handle numbers in range ]0;1[ correctly
	if(tmp < factor) {
		tmp = factor;
	}

	while(tmp != 0) {
		tmp /= 10;
		ndigits++;
	}

	if(frac_digits > 0) {
		ndigits++; // for the decimal point
	}

	// write the digits
	tmp = v_scaled;

	ptr = str + ndigits - 1;

	while(digits_written < ndigits) {
		*(ptr--) = '0' + (tmp % 10);
		digits_written++;

		if(digits_written == frac_digits) {
			*(ptr--) = '.';
			digits_written++;
		}

		tmp /= 10;
	}

	str[ndigits] = '\0';

	if(v < 0) {
		return ndigits + 1; // for the sign
	} else {
		return ndigits;
	}
}

void fxp_right_align(char *in, char *out, unsigned int width, char fill)
{
	unsigned int inlen = 0;
	char *ptr;

	ptr = in;
	while(*ptr) {
		inlen++;
		ptr++;
	}

	if(inlen > width) {
		// if input does not fit in width characters, do left align, as right align
		// does not really make much sense here (assuming numbers).
		for(unsigned int i = 0; i < width; i++) {
			*(out++) = *(in++);
		}
	} else {
		// proper right align
		for(unsigned int i = 0; i < width; i++) {
			if(i < (width - inlen)) {
				*(out++) = fill;
			} else {
				*(out++) = *(in++);
			}
		}
	}

	*out = '\0';
}
