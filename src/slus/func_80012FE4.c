#include "types.h"
#include "addr.h"

void func_80012FE4(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        ((Obj80012FE4*)D_801F8300)->f60[i] = 0;
    }
    for (i = 0; i < 16; i++) {
        *(D_801F8300 + i + 0x71) = 0;
    }
}
