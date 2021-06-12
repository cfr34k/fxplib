# fxplib – A simple fixed-point arithmetic library

This library provides simple fixed-point arithmetic that can be used, for
example, in embedded software. It is intended to be used on 32-bit systems.

## Configuration

The fixed-point precision is constant for the entire program and defined using
the `POINTPOS` macro which defines the number of bits used for the fractional
part. It is best set via a compiler option like `-DPOINTPOS=20`. If it is not
defined, a warning is produced and it is set to 16.

## Usage example

The following code demonstrates the basic usage of _fxplib_’s arithmetic and
number formatting functions.

```c
#include <stdio.h>

#include <fxp.h>        // contains the "fancy" stuff
#include <fxp_basic.h>  // contains the simple, inlineable arithmetic

int main(void)
{
  char printbuf[FXP_STR_MAXLEN];

  fxp_t a, b, x;

  a = FXP_FROM_INT(10);   // => a = 10
  b = fxp_inv(a);         // => b = 0.1
  b = fxp_add(b, b);      // => b = 0.2

  x = fxp_mult(a, b);     // => x = 2.0

  // format the number with three fractional decimal digits
  fxp_format(a, printbuf, 3);

  // note that printf is not used anywhere!
  fputs(printbuf, stdout);
  fputs(" / ", stdout);

  fxp_format(b, printbuf, 3);
  fputs(printbuf, stdout);
  fputs(" = ", stdout);

  fxp_format(x, printbuf, 3);
  fputs(printbuf, stdout);
  fputs("\n", stdout);
}
```

To build it, save it to a file (assuming `demo.c` here) and run the following
commands:

```bash
make        # to build fxplib
gcc -Wall -std=c99 -pedantic -ggdb -Iinclude -Llib/debug -o demo demo.c -lfxp_default
```

## License

This code is licensed under the [MIT license](LICENSE).
