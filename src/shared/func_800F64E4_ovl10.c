/* Shared body (DK-5), from the banked draft of func_800F64E4_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_8002E198(void);
extern void func_8003D010(s8 dmg);
extern u8 D_8009A0A0[];

void DEDUP_NAME(u8* obj) {
    u8 t;
    s16 old;
    s32 cnt;
    s32 was;

    t = (*(u8**)(obj + 0x7C))[0x47];
    if (t == 0x76 || t == 0x7F) {
        func_800171E8(obj, 4);
    } else {
        func_800171E8(obj, 0x18);
    }
    func_800171E8(obj, 4);
    if (D_8009A0A0[0x5C] & 0x7F) {
        old = *(s16*)(obj + 0x90);
        *(s16*)(obj + 0x90) += func_8002E198();
        if (old != *(s16*)(obj + 0x90)) {
            *(u16*)(obj + 0x42) |= 0x8000;
        } else {
            *(u16*)(obj + 0x42) &= 0x7FFF;
        }
    } else {
        *(u16*)(obj + 0x42) &= 0x7FFF;
    }
    cnt = *(s32*)(obj + 0x84);
    was = cnt;
    cnt--;
    *(s32*)(obj + 0x84) = cnt;
    if (was == 0) {
        func_8003D010(6);
        was = 0x3C;
        *(s32*)(obj + 0x84) = was;
    }
    if (*(s16*)(obj + 0x90) >= 30) {
        obj[0x62] = 0;
        D_8009A0A0[0xCA] = 0;
        obj[4] = 2;
    }
}
