/* Shared body (DK-5), from the banked draft of func_800F7374_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80016490(s32, s32, void*);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern u8 D_800FA218_ovl03[];
extern u8 D_800FA21C_ovl03[];

void DEDUP_NAME(u8* a0) {
    u8* p;

    func_800317B8(a0);
    func_80031DD0(a0);
    switch (((s8*)a0)[5]) {
    case 0:
        if (--*(s32*)(a0 + 0x84) == 0) {
            func_800171E8(a0, 0xE);
            func_80016490(2, 0xF, a0);
            if (a0[0x15] == 0) {
                *(s32*)(a0 + 0x20) = -0x10000;
            } else {
                *(s32*)(a0 + 0x20) = 0x10000;
            }
            *(s32*)(a0 + 0x84) = 0;
            a0[5]++;
            func_8002D9EC(a0, 0x10, 0x10);
        }
        break;
    case 1:
        if (((s8*)a0)[0x45] != 0) {
            if (((s8*)a0)[2] == 1 || ((s8*)a0)[2] == 4) {
                *(u8**)(a0 + 0x50) = D_800FA218_ovl03;
                *(u8**)(a0 + 0x54) = D_800FA21C_ovl03;
            }
        }
        if (++*(s32*)(a0 + 0x84) == 700) {
            a0[4] = 2;
        }
        func_8002D9EC(a0, 0x10, 0x10);
        break;
    }
    p = *(u8**)(a0 + 0x7C);
    if (((s8*)p)[4] == 2 || ((s8*)p)[5] == 10) {
        a0[4] = 2;
    }
    func_80017248(a0);
    func_8002DED4(a0);
}
