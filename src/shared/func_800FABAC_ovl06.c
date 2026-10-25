/* Shared body (DK-5), from the banked draft of func_800FABAC_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80016490(s32, s32, void*);
extern u8 D_800FF1D4_ovl06[];
extern u8 D_800FF1D8_ovl06[];

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        *(u8*)(obj + 0x9A) = 1;
        func_800171E8(obj, 0x19);
        *(void**)(obj + 0x50) = D_800FF1D4_ovl06;
        *(void**)(obj + 0x54) = D_800FF1D8_ovl06;
        if (*(u8*)(obj + 0x15) == 0) {
            *(s32*)(obj + 0x20) = -0x60000;
        } else {
            *(s32*)(obj + 0x20) = 0x60000;
        }
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(u16*)(obj + 0x7C) = 1;
        *(u16*)(obj + 0x7E) = 0;
        func_80016490(2, 0x22, obj);
        obj[6]++;
    }
}
