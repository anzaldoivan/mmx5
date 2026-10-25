#include "types.h"

extern u8 D_8009A0A0[];
extern s8 D_800D1C1C;
extern s32 func_80031670(u8* a0, s8 dmg);

void func_8003D010(s8 dmg) {
    u8* p;

    p = D_8009A0A0;
    ((s8*)p)[0xCA] = -1;
    if (p[0x5C] & 0x7F) {
        if (dmg != 0) {
            p[0x5C] -= func_80031670(p, dmg);
        }
        if (((s8*)p)[0x5C] > 0) {
            p[0x5C] |= 0x80;
        } else {
            p[0xCA] = 0;
            D_800D1C1C = 1;
            ((s8*)p)[0x5C] = -0x80;
        }
    }
}
