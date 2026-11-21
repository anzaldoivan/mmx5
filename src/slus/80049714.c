#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void (*D_80077114[])(u8*);

void func_80049714(u8* p) {
    if (is_off_screen(p, 0x30, 0x30) == 0 && *(s8*)(p + 0x98) == 0) {
        D_80077114[p[0x8E] - 1](p);
    } else {
        p[4] = 2;
    }
}

#define func_80046A6C func_8004978C
#include "shared/func_80046A6C.c"
#undef func_80046A6C
