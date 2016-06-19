#include <stdio.h>
#include <stdint.h>

#include <fxp.h>
#include <fxp_basic.h>

int main(void)
{
	fxp_t a, b, c, d, e, x;

	char number[11];

	fxp_format_int(10, number); printf("%s\n", number);
	fxp_format_int(-10, number); printf("%s\n", number);
	fxp_format_int(0, number); printf("%s\n", number);
	fxp_format_int(99, number); printf("%s\n", number);
	fxp_format_int(100, number); printf("%s\n", number);
	fxp_format_int(-32768, number); printf("%s\n", number);
	fxp_format_int(2147483647, number); printf("%s\n", number);
	fxp_format_int(-2147483648, number); printf("%s\n", number);

	a = fxp_from_float(0.5);
	b = fxp_from_float(-100);
	c = fxp_from_float(0.3);
	d = fxp_from_float(10);
	e = fxp_from_float(1);

	x = fxp_mult(a, b); // 50
	printf("%f\n", fxp_to_float(x));

	x = fxp_add(x, c);  // 50.3
	printf("%f\n", fxp_to_float(x));

	x = fxp_div(x, d);  // 5.03
	printf("%f\n", fxp_to_float(x));

	x = fxp_div(e, x);  // 0.19...
	printf("%f\n", fxp_to_float(x));

	fxp_format_int((x * 100) >> POINTPOS, number); printf("%s\n", number);

	return 0;
}
