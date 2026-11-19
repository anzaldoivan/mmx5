#include "types.h"
#include "mmx5/globals.h"

extern s8 D_800D1C44;

void func_800EF170_ovl23(u8* obj) {
    s8 v = D_800D1C44;

    if (v == 1) {
        ((s8*)obj)[3] = v;
    } else {
        ((s8*)obj)[3] = 0;
    }
    animate_object();
}
