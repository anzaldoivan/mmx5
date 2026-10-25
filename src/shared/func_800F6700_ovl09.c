/* Shared body (DK-5), from the banked draft of func_800F6700_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_8002D9EC();
extern int func_8002D6FC();
extern u8 D_800D1C00[];

void DEDUP_NAME(u8* arg0) {
    signed char* p;
    u8* d;

    p = *(signed char**)(arg0 + 0x80);
    if (p[0] != 0) {
        if (p[7] == 0) {
            if (--*(s16*)(arg0 + 0x7E) == -1) {
                *(s16*)(arg0 + 0x7E) = 5;
                *(u16*)(arg0 + 0x42) ^= 0x8000;
            }
            func_8002D9EC(arg0, 0x40, 0x40);
        }
    } else {
        d = D_800D1C00;
        if (*(signed char*)(d + 0xC) != 12) {
            *(signed char*)(d + 0xF) = 0x10;
        } else {
            *(signed char*)(d + 0xF) = -0x80;
            d[*(signed char*)(d + 0x1D) + 0x2C] = 1;
            d[0x1D] += 9;
        }
        func_8002D6FC(arg0);
    }
}
