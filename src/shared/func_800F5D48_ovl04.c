/* Shared body (DK-5), from the banked draft of func_800F5D48_ovl04 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D6FC(u8* obj);
extern void func_8002D89C(u8* obj);
extern u8 D_800D1C00[];

void DEDUP_NAME(u8* obj) {
    s8* child;
    u8* base;

    func_80017248(obj);
    child = *(s8**)(obj + 0x80);
    obj[3] = 0;
    if (child[0] != 0) {
        if (child[7] == 0) {
            if (--*(s16*)(obj + 0x7E) == -1) {
                *(u16*)(obj + 0x7E) = 5;
                *(u16*)(obj + 0x42) ^= 0x8000;
            }
            func_8002D89C(obj);
        }
    } else {
        base = D_800D1C00;
        if (((s8*)base)[0xC] != 0xC) {
            base[0xF] = 0x10;
        } else {
            ((s8*)base)[0xF] = -0x80;
            base[((s8*)base)[0x1D] + 0x2C] = 1;
            base[0x1D] += 9;
        }
        func_8002D6FC(obj);
    }
}
