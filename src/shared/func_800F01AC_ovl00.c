/* Shared body (DK-5), from the banked draft of func_800F01AC_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern u8* func_8002C938();
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800FA78C_ovl00[];
extern s32 D_8009A0A8;

void DEDUP_NAME(u8* obj) {
    u8* p;

    D_1F80004C.bytes[0x85] = 0;
    p = func_8002C938();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = obj[1];
        p[2] = 0x10;
        *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
        *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
        *(s32*)(p + 0x10) = 0;
        *(u8**)(p + 0x80) = obj;
        *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
        *(u16*)(p + 0x42) = *(u16*)(obj + 0x42);
        *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
        D_1F80004C.bytes[0x85] = 1;
        *(u8**)(D_1F80004C.bytes + 0x80) = p;
        (*(u8**)(D_1F80004C.bytes + 0x80))[0x84] = 1;
    }
    if (((s8*)obj)[2] == 0) {
        D_1F80004C.bytes[0x91] = 1;
        *(u8**)(obj + 0x54) = D_800FA78C_ovl00;
        obj[0x15] = (*(s32*)(obj + 8) <= D_8009A0A8) << 6;
        func_800171E8(obj, 0xE);
    }
    obj[6]++;
}
