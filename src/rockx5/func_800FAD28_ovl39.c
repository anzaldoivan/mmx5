#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_8009A0A0[];

void func_800FAD28_ovl39(u8* obj) {
    u8* d = D_8009A0A0;
    s32 a;

    a = (ratan2(*(s16*)(d + 0xE) - *(s16*)(obj + 0xE),
                *(s16*)(d + 0xA) - *(s16*)(obj + 0xA)) +
         0x1000) &
        0xFFF;
    if (*(s8*)(obj + 2) == 0) {
        if (a < 0x800) {
            a = 0x800;
        } else if (a >= 0x956) {
            a = 0x955;
        }
    } else if ((u32)(a - 1) < 0x3FF) {
        a = 0;
    } else if (a < 0xEAB) {
        a = 0xEAB;
    }
    *(s32*)(obj + 0x20) = rcos(a) * 0x50;
    *(s32*)(obj + 0x24) = (-rsin(a) * 0x50) >> 1;
    *(s32*)(obj + 0x20) = *(s32*)(obj + 0x20) >> 1;
    func_800171E8(obj, 0);
    obj[6]++;
}
