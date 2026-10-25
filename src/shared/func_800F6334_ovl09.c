/* Shared body (DK-5), from the banked draft of func_800F6334_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80016D54(s32, s32);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern u8 D_800FAB9C_ovl09[];
extern u8 D_800FABA4_ovl09[];

void DEDUP_NAME(u8* obj) {
    func_80016D54(2, 0x26);
    func_800171E8(obj, 2);
    *(u8**)(obj + 0x50) = D_800FAB9C_ovl09;
    *(u8**)(obj + 0x54) = D_800FABA4_ovl09;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0x8000;
    obj[6]++;
    func_80017248(obj);
    func_8002DED4(obj);
}
