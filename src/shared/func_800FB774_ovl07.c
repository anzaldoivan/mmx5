/* Shared body (DK-5), from the banked draft of func_800FB774_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern u8 D_8009A0A0[];
extern void func_8003D29C(s32, s32);
extern void func_800171E8(u8*, s32);
extern void func_8002D9EC(u8*, s32, s32);

void DEDUP_NAME(u8* arg0) {
    D_1F80004C.scr2074->pad8E = 1;
    D_1F80004C.scr2074->unk92 = 0;
    D_8009A0A0[0xCA] = 0;
    func_8003D29C(0x14, D_8009A0A0[0x15]);
    arg0[5] = 1;
    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    func_800171E8(arg0, 0x19);
    *(s16*)(arg0 + 0x7C) = 0x7F;
    *(s16*)(arg0 + 0x7E) = 0x19;
    arg0[0x61] = 0x19;
    func_8002D9EC(arg0, 0x60, 0x60);
}
