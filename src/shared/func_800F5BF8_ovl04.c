/* Shared body (DK-5), from the banked draft of func_800F5BF8_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8003D29C(s32, s32);
extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_8002D89C(u8*);
extern u8 D_8009A0B5;

void DEDUP_NAME(u8* obj) {
    func_8003D29C(0x14, D_8009A0B5);
    obj[5]++;
    func_800171E8(obj, 0x1C);
    *(s16*)(obj + 0x7C) = 0x7F;
    *(s16*)(obj + 0x7E) = 0x19;
    obj[0x89] = 0x19;
    func_80017248(obj);
    func_8002D89C(obj);
}
