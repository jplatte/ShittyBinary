# Binary
A library I ported to C, because C only supports base 10 and base 16. Try it for yourself!

This is a port of https://github.com/jplatte/ShittyBinary

Send any suggestions to the maintainer of the C++ library, not me.

## Example
```C
#ifdef _cplusplus
using namespace std;
#else
#include <stdio.h>
#endif

#include "binc.h"

void main(void) {
    CBinary * x = cb_Create("0100010010");
    CBinary * y = cb_Create("1010001010");

    char * str1 = cb_ToString(cb_Not(x));
    char * str2 = cb_ToString(cb_Not(y));
    char * str5 = cb_ToString(cb_And(x, y));
    char * str3 = cb_ToString(cb_Or(y, x));
    char * str4 = cb_ToString(cb_Xor(x, y));

    printf("%s\n%s\n%s\n%s\n%s\n", str1, str2, str5, str3, str4);
}
```

Port copyright (r) 2016 cmpsb.net (tm)

Logic copyright (r) 2016 jplatte

Nand patch copyright (r) 2016 cmpsb.nl (tm)