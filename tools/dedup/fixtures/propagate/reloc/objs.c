/* Selftest reloc sources (hand-written): the rep, a member whose global differs (renamed), a member whose global
   lives in another overlay (refused). One object; propagate.relocs reads each function's relocations from it. */
#include "types.h"

extern s32 fx_d_a, fx_d_b, fx_d_c_ovl09;

void func_80001100(void) {
    fx_d_a = 1;
}

void func_80001110(void) {
    fx_d_b = 1;
}

void func_80001120(void) {
    fx_d_c_ovl09 = 1;
}
