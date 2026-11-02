/* Shared body (DK-5), from the banked draft of func_800F60F8_ovl10 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D27C(void);

void DEDUP_NAME(u8* obj) {
    s8 state;
    u8* p;

    func_80017248(obj);
    state = *(s8*)(obj + 0x45);
    if (state == 1) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x23;
            p[2] = state;
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42);
            p[0x15] = obj[0x15];
            p[0x14] = obj[0x14];
            *(s32*)(p + 0x8) = *(s32*)(obj + 0x8) + 0xFFE00000;
            *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
        }
        obj[6] = state;
        *(s16*)(obj + 0x7E) = 0x84;
    }
}
