/* Selftest target (hand-written): the member as one TU, compiled with the pin for the target bytes. */
#include "types.h"

extern void fx_callee(u8* o);

void func_80001000(u8* o) {
    o[3] = 0;
    fx_callee(o);
}
