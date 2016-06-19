#include "fxp.h"

void fxp_format_int(int32_t n, char *str)
{
	int ndigits;
	int32_t tmp;
	char *ptr;

	if(n == 0) {
		str[0] = '0';
		str[1] = '\0';
		return;
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
}

