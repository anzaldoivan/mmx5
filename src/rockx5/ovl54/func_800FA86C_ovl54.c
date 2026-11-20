#include "types.h"

extern void func_800177B0(s32, s32);

void func_800FA86C_ovl54(u8* o) {
    if (++*(s16*)(o + 4) >= 10) {
        func_800177B0(0x1B, 0x7F);
        o[1]++;
    }
}
