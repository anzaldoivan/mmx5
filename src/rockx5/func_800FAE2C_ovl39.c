#include "types.h"

extern void func_8002DF54(u8* a0);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);

static inline void func_800FAE2C_ovl39_aim(u8* a0, s32 x) {
    s32 ang;

    ang = ratan2(0x820 - *(s16*)(a0 + 0xE), x - *(s16*)(a0 + 0xA));
    *(s32*)(a0 + 0x20) = rcos(ang) * 0x30;
    *(s32*)(a0 + 0x24) = (-rsin(ang) * 0x30) >> 1;
    *(s32*)(a0 + 0x20) = *(s32*)(a0 + 0x20) >> 1;
    a0[6]++;
}

void func_800FAE2C_ovl39(u8* a0) {
    func_8002DF54(a0);
    if (*(s8*)(a0 + 2) == 0 && *(s16*)(a0 + 0xA) < 0x11C1) {
        func_800FAE2C_ovl39_aim(a0, 0x1290);
    } else if (*(s8*)(a0 + 2) == 1 && *(s16*)(a0 + 0xA) >= 0x1260) {
        func_800FAE2C_ovl39_aim(a0, 0x1190);
    }
}
