/* Shared body (DK-5), from the banked draft of func_800F0E00_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A0A0[];
extern u16 D_800F2100_ovl12;

void DEDUP_NAME(u8* obj) {
    u8* d;
    u8* d2;
    s32 t;
    u16 e;

    if (((s8*)*(u8**)(obj + 0x80))[7] != 0) {
        d = D_8009A0A0;
        if (*(s16*)(d + 0xA) < *(s16*)(obj + 0xA)) {
            d[0x15] = 0x40;
        } else {
            d[0x15] = 0;
        }
        *(u16*)(obj + 0x42) &= 0x7FFF;
        d2 = D_8009A0A0;
        if (*(s16*)(d2 + 0xA) > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        func_800171E8(obj, 0xB);
        e = D_800F2100_ovl12;
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x68) = 0;
        *(u16*)(obj + 0xE) = e;
        obj[5]++;
        return;
    }
    t = *(u16*)(obj + 0x7E) - 1;
    *(u16*)(obj + 0x7E) = t;
    if ((s16)t == -1) {
        *(u16*)(obj + 0x7E) = 5;
        *(u16*)(obj + 0x42) ^= 0x8000;
    }
    func_8002D9EC(obj, 0x40, 0x40);
}
