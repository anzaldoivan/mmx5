/* Shared body (DK-5), from the banked draft of func_800F04D8_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8*, s32);
extern int func_8002D6FC();
extern void func_80017248(u8*);
extern void func_8002D89C(u8*);

void DEDUP_NAME(u8* a0) {
    u8* p;

    if (*(signed char*)(a0 + 7) != *(signed char*)(*(u8**)(a0 + 0x50) + 7)) {
        func_800171E8(a0, 2);
    }
    p = *(u8**)(a0 + 0x50);
    a0[7] = p[7];
    *(s32*)(a0 + 8) = *(s32*)(p + 8);
    *(s16*)(a0 + 0xE) = *(s16*)(p + 0xE) - 0x20;
    if (p[0x47] == 10) {
        func_8002D6FC(a0);
        return;
    }
    func_80017248(a0);
    a0[0x54] = (signed char)(a0[0x54] + 1) % 90;
    if (*(signed char*)(a0 + 7) == 0 && (signed char)a0[0x54] < 30) {
        a0[3] = 0;
        return;
    }
    func_8002D89C(a0);
}
