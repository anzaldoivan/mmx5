/* Shared body (DK-5), from the banked draft of func_800EEC38_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern s32 func_8002385C(s32, s32, s32);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002DF54(u8* a0);
extern u8 D_800D1C00[];
extern u8 D_800F1BC0_ovl12[];

void DEDUP_NAME(u8* arg0) {
    u8* p;
    s32 snd;

    if (*(u8**)(arg0 + 0x68) == 0 && *(s16*)(arg0 + 0xE) >= 0x12C) {
        *(u8**)(arg0 + 0x68) = D_800F1BC0_ovl12;
    }
    if (arg0[0x70] & 8) {
        *(s32*)(arg0 + 0x24) = 0;
    }
    if (*(s8*)(arg0 + 0x46) == 0) {
        p = D_800D1C00;
        if (*(s8*)(p + 0xC) != 0xC) {
            snd = 0x35;
            if (*(s8*)(arg0 + 2) == 0) {
                snd = 0x33;
            }
            func_8002385C(snd, 0xFF, *(s8*)(p + 0x2E));
            p[0x2E] = 1;
        }
        func_800171E8(arg0, 1);
        *(s16*)(arg0 + 0x7C) = 3;
        arg0[6]++;
    }
    func_80017248(arg0);
    func_8002DF54(arg0);
    func_8002D9EC(arg0, 0x40, 0x40);
}
