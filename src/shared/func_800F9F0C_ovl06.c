/* Shared body (DK-5), from the banked draft of func_800F9F0C_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_800FAF38_ovl06(u8*, s32, s32, s32);
extern u8 D_800FF1DC_ovl06[];
extern u8 D_800FF1E0_ovl06[];

void DEDUP_NAME(u8* obj) {
    s8 state;

    func_80017248(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        func_800171E8(obj, 10);
        *(u16*)(obj + 0x7C) = 40;
    }
    state = *(s8*)(obj + 0x45);
    if (state == 2) {
        func_80016490(2, 0x1F, obj);
        func_800FAF38_ovl06(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 1);
    } else if (state == 3) {
        if (--*(s16*)(obj + 0x7E) == 0) {
            func_800171E8(obj, 20);
            *(u8**)(obj + 0x50) = D_800FF1DC_ovl06;
            *(u8**)(obj + 0x54) = D_800FF1E0_ovl06;
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x24) = 0;
            *(s32*)(obj + 0x2C) = 0x3000;
            obj[6]++;
        }
    }
}
