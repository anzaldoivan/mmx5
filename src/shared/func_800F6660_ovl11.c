/* Shared body (DK-5), from the banked draft of func_800F6660_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800F81F4_ovl11(u8* obj);
extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();
extern s32 func_8002B5B4(s32);
extern signed char D_800D1C0C;

void DEDUP_NAME(u8* obj) {
    u8* p;
    s32 a;
    s32 b;
    s32 v;

    func_800F81F4_ovl11(obj);
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) != 1) {
        return;
    }
    p = func_8002D1A4();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 5;
        p[2] = 0;
        *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
        if (D_800D1C0C == 12) {
            v = 0x7CCA;
        } else {
            a = func_8002B5B4(*(s8*)(obj + 1));
            b = func_8002B5B4(*(s8*)(obj + 1));
            v = ((a * 4 + 0x1A) % 16) | (((b + 6) / 4 + 0x1E0) << 6);
        }
        *(u16*)(p + 0x42) = v;
        *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
        p[0x14] = obj[0x14];
        p[0x15] = obj[0x15];
        if (p[0x15] != 0) {
            *(s32*)(p + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(p + 0x20) = 0x80000;
        } else {
            *(s32*)(p + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(p + 0x20) = -0x80000;
        }
        *(s32*)(p + 0x24) = 0;
        *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
        *(u8**)(p + 0x7C) = obj;
        *(u8**)(D_1F80004C.bytes + 0x80) = p;
        obj[7] = 1;
        *(s16*)(obj + 0x7C) = 10;
    }
    obj[6]++;
}
