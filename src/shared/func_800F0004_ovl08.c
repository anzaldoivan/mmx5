/* Shared body (DK-5), from the banked draft of func_800F0004_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D1A4();
extern void func_8002E058(void* obj, s32 kind);

void DEDUP_NAME(u8* obj) {
    u8* p;
    s32 t;

    func_80017248(obj);
    t = obj[0x81];
    if ((u32)(t - 9) < 15) {
        if (obj[0x15] != 0) {
            *(u16*)(obj + 0x7C) = 10;
            obj[6] = 3;
        }
    } else if ((u8)(t - 8) >= 17 && obj[0x15] == 0) {
        *(u16*)(obj + 0x7C) = 10;
        obj[6] = 3;
    }
    if (*(s8*)(obj + 6) != 3) {
        func_800171E8(obj, 4);
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0xE;
            p[2] = obj[2];
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42);
            /* t reused: its second set hides t's 0..255 range, so the andi 0xFF test above stays */
            t = *(s32*)(obj + 0x30);
            *(s32*)(p + 0x30) = t;
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            p[0x15] = obj[0x15];
            p[0x14] = obj[0x14];
            *(s32*)(p + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
            func_8002E058(p, obj[0x81]);
            p[4] = 0;
            *(s32*)(p + 0x20) = *(s32*)(p + 0x20) * 3;
            *(s32*)(p + 0x24) = *(s32*)(p + 0x24) * 3;
        }
        if (--*(s16*)(obj + 0x7C) == 0) {
            *(u16*)(obj + 0x7C) = 10;
            obj[6] = 3;
            return;
        }
        *(u16*)(obj + 0x7E) = 0x14;
        obj[6] = 1;
    }
}
