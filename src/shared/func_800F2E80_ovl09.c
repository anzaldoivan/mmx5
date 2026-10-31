/* Shared body (DK-5), from the banked draft of func_800F2E80_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s32 func_8002E024(void*, void*);
extern void func_8002E0F8(s32* a0, s32* a1, u8 a2);
extern u8 D_8009A0A0[];
extern s16 D_800FB62E_ovl09;
extern s16 D_800FB630_ovl09;
extern s32 D_800FB67C_ovl09;

void DEDUP_NAME(u8* o) {
    u32 max;
    s32 t1;
    s32 t2;
    u16 scale;
    s32 r;
    s16 v;

    if (D_800FB67C_ovl09 != 0) {
        max = 0x60000;
        t1 = 0x1E;
        t2 = 0x3C;
    } else {
        max = 0x40000;
        t1 = 0x23;
        t2 = 0x46;
    }
    *(u32*)(o + 0x84) += *(u32*)(o + 0x88);
    if (max < *(u32*)(o + 0x84)) {
        *(u32*)(o + 0x84) = max;
    }
    scale = *(u16*)(o + 0x86);
    func_8002E0F8((s32*)(o + 0x20), (s32*)(o + 0x24), o[0x92]);
    *(s32*)(o + 0x20) *= scale;
    *(s32*)(o + 0x24) *= scale;
    if (*(s16*)(o + 0x7C) == t1) {
        r = func_8002E024(o, D_8009A0A0);
        o[0x92] = r;
        if ((u8)r < 9) {
            o[0x92] = 0x1F;
        } else if ((u8)(r - 9) < 8) {
            o[0x92] = 0x11;
        }
    }
    if (++*(s16*)(o + 0x7C) == t2 || o[0x93] != 0) {
        func_800171E8(o, 0);
        *(s32*)(o + 0x20) = 0;
        *(s32*)(o + 0x24) = 0x30000;
        o[6]++;
    }
    func_80017248(o);
    func_8002DED4(o);
    if (*(s16*)(o + 0xA) < D_800FB62E_ovl09 - 8) {
        *(s16*)(o + 0xA) = D_800FB62E_ovl09 - 8;
    } else if (D_800FB630_ovl09 + 8 < *(s16*)(o + 0xA)) {
        *(s16*)(o + 0xA) = D_800FB630_ovl09 + 8;
    }
}
