/* Shared body (DK-5), from the banked draft of func_800FBA84_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A0A0[];
extern s8 D_800D1C1D;
extern void func_8002DF54(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* obj) {
    u8* g = D_8009A0A0;

    if (*(s16*)(g + 0xA) > 0x1100) {
        if (g[0xF7] == 0) {
            func_8002DF54(obj);
        }
        func_8002D9EC(obj, 0xF0, 0x20);
    }
    if (D_800D1C1D == 4) {
        obj[4]++;
    }
}
