/* Shared body (DK-5), from the banked draft of func_800F55A4_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D1A4();
extern u8 D_800FC1C8_ovl10[];

void DEDUP_NAME(u8* obj) {
    u8* p;

    func_80017248(obj);
    p = func_8002D1A4();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x27;
        if (D_800FC1C8_ovl10[1] != 0) {
            p[2] = 1;
            *(s16*)(obj + 0x92) = 0x12C;
            p[4] = 7;
            *(s32*)(p + 0x24) = 0x40000;
        } else {
            p[2] = 0;
            p[4] = 4;
            *(s32*)(p + 0x24) = 0;
        }
        if (obj[0x15] != 0) {
            *(s32*)(p + 0x20) = 0x40000;
            *(s32*)(p + 8) = *(s32*)(obj + 8) + 0x300000;
        } else {
            *(s32*)(p + 0x20) = 0xFFFC0000;
            *(s32*)(p + 8) = *(s32*)(obj + 8) + 0xFFD00000;
        }
        *(s16*)(p + 0x40) = *(s16*)(obj + 0x40);
        *(s16*)(p + 0x42) = *(s16*)(obj + 0x42) & 0x7FFF;
        *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
        p[0x14] = obj[0x14];
        *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
        p[0x15] = obj[0x15];
        *(u8**)(p + 0x7C) = obj;
    }
    obj[6] = 4;
}
