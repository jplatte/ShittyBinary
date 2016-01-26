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