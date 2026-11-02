/* Shared body (DK-5), from the banked draft of func_800FAD14_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8001296C(s32);
extern void func_80016490(s32, s32, u8*);
extern void func_800171E8(u8*, s32);
extern void func_80017248(u8*);
extern void func_8002A600(s32, s32, s32);
extern void func_8002DED4(u8*);
extern s8 D_800D1C0C;
extern u8 D_800FD608_ovl01[];

void DEDUP_NAME(u8* arg0) {
    s32 lim;

    lim = 0x40;
    if (D_800D1C0C != 0xC) {
        lim = 0x120;
    }
    func_80017248(arg0);
    func_8002DED4(arg0);
    if (lim < *(s16*)(arg0 + 0xE)) {
        *(u8**)(arg0 + 0x68) = D_800FD608_ovl01;
    }
    if (arg0[0x70] & 8) {
        func_8001296C(5);
        arg0[0x15] = 0;
        func_800171E8(arg0, 0x10);
        func_80016490(2, 7, arg0);
        func_8002A600(0x1E, 4, 2);
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        *(s32*)(arg0 + 0x2C) = 0;
        arg0[6] = 4;
    }
}
