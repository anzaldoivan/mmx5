#include "types.h"

extern s16 D_8009A0AA;

s32 func_800F1B88_ovl10(Obj3DD4* e) {
    s32 d = D_8009A0AA;
    s32 y = e->unkA;
    if (((d - y) < 0 ? (y - d) : (d - y)) < 0x60) {
        return 1;
    }
    return 0;
}
