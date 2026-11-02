/* Shared body (DK-5), from the banked draft of func_800FBC2C_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_80044DD0(s32 a0);
extern u16 D_80093E68;
extern s16 D_8009A220[];
extern u16 D_8009A42E;
extern u8 D_800C9310;
extern signed char D_800D1C0C;
extern u16 D_800D50DE;

void DEDUP_NAME(u8* arg0) {
    func_80017248(arg0);
    if (--((s16*)arg0)[0x3E] == -1) {
        ((s16*)arg0)[0x3E] = 6;
        D_800D50DE--;
        D_8009A42E -= 0x20;
        D_80093E68 -= 0x400;
        D_800C9310 |= 1;
        if (D_800D50DE < 0xB) {
            if (D_800D1C0C != 0xC) {
                D_8009A220[1] = 0x440;
            }
            func_80044DD0(0);
            ((s16*)arg0)[0x3E] = 2;
            arg0[6]++;
        }
    }
}
