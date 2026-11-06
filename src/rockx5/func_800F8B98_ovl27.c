#include "types.h"

extern void func_8002DF54(u8* a0);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);

void func_800F8B98_ovl27(u8* a0) {
    s32 ang;
    s32 v;
    s16 t;

    ang = ratan2(*(s16*)(a0 + 0xE) - 0x90, 0x1340 - *(s16*)(a0 + 0xA));
    *(s32*)(a0 + 0x28) = 0;
    *(s32*)(a0 + 0x2C) = 0;
    *(s32*)(a0 + 0x20) = rcos(ang) * 16;
    *(s32*)(a0 + 0x24) = rsin(ang) * 16;
    v = *(s32*)(a0 + 0x20);
    if (v != 0) {
        *(s32*)(a0 + 0x20) = v * 2;
    } else {
        *(s32*)(a0 + 0x20) = 0;
    }
    if (*(s32*)(a0 + 0x24) != 0) {
        *(s32*)(a0 + 0x24) = *(s32*)(a0 + 0x24) * 2;
    } else {
        *(s32*)(a0 + 0x24) = 0;
    }
    func_8002DF54(a0);
    t = *(s16*)(a0 + 0xA);
    if (t >= 0x133D) {
        if (t < 0x1344) {
            t = *(s16*)(a0 + 0xE);
            if (t >= 0x8D) {
                if (t < 0x94) {
                    *(s16*)(a0 + 0xA) = 0x1340;
                    *(s16*)(a0 + 0xE) = 0x90;
                    a0[6]++;
                }
            }
        }
    }
}
