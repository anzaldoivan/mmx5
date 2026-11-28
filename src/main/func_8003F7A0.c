#include "types.h"

s32 func_8003E6FC(void*, s8);

s32 func_8003F7A0(HudObj* a0) {
    s16 v = a0->unkA8[a0->unk93];

    if (v == 0) {
        return 0;
    }
    return v >= func_8003E6FC(a0, a0->unk94);
}
