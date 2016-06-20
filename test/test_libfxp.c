#include <stdio.h>
#include <stdint.h>

#include <fxp.h>
#include <fxp_basic.h>

int main(void)
{
	fxp_t a, b, c, d, e, x;
	int n;

	char number[FXP_STR_MAXLEN];

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

	x = fxp_mult(a, b); // -50
	printf("%f\n", fxp_to_float(x));

	x = fxp_add(x, c);  // -49.7
	printf("%f\n", fxp_to_float(x));

	x = fxp_div(x, d);  // -4.97
	printf("%f\n", fxp_to_float(x));

	x = fxp_div(e, x);  // -0.20...
	printf("%f\n", fxp_to_float(x));

	printf("+++\n");

	a = fxp_from_int(1000);
	b = fxp_inv(a);
	c = fxp_from_float(5.124);
	x = fxp_mult(b, c); // 0.005124

	printf("%f\n", fxp_to_float(a));
	printf("%f\n", fxp_to_float(b));
	printf("%f\n", fxp_to_float(c));
	printf("%f\n", fxp_to_float(x));

	printf("+++ FORMAT TEST:\n");

	x = fxp_from_float(3.56);
	n = fxp_format(x, number, 0); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 1); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 2); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 3); printf("[%i] %s\n", n, number);

	x = fxp_from_float(99.99);
	n = fxp_format(x, number, 0); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 1); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 2); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 3); printf("[%i] %s\n", n, number);

	x = fxp_from_float(-4.71);
	n = fxp_format(x, number, 0); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 1); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 2); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 3); printf("[%i] %s\n", n, number);

	x = fxp_from_float(-0.01);
	n = fxp_format(x, number, 0); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 1); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 2); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 3); printf("[%i] %s\n", n, number);

	x = fxp_from_float(0.01);
	n = fxp_format(x, number, 0); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 1); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 2); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 3); printf("[%i] %s\n", n, number);

	x = fxp_from_int(0);
	n = fxp_format(x, number, 0); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 1); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 2); printf("[%i] %s\n", n, number);
	n = fxp_format(x, number, 3); printf("[%i] %s\n", n, number);

	return 0;
}
