/* Shared body (DK-5), from the banked draft of func_800EF478_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_80017248(u8* obj);
extern u8* func_8002D1A4();
extern s32 func_800171E8(u8* obj, s32 state);

void DEDUP_NAME(u8* obj) {
    u8* p;

    func_80017248(obj);
    if (*(s8*)(obj + 0x45) != 0) {
        *(s8*)(obj + 0x45) = 0;
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 8;
            *(s32*)(p + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42);
            p[0x14] = obj[0x14];
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            p[0x15] = obj[0x15];
        }
    }
    if (*(s8*)(obj + 0x46) == 0) {
        obj[5] = 1;
        obj[6] = 0;
        func_800171E8(obj, 1);
        obj[0x83] = 0x78;
        obj[0x80] &= 0xFD;
    }
}
