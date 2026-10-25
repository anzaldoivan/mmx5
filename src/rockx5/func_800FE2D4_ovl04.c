#include "types.h"

extern u8 D_800D1C00[];
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800FE2D4_ovl04(u8* arg0) {
    u8* p = D_800D1C00;

    if (p[0x28] & arg0[0x93]) {
        arg0[0x95] = ~arg0[0x93];
        arg0[0x96] = 0xFF;
        arg0[5]++;
    }
    if (((s8*)p)[0x28] == 0 && (p[0x29] & arg0[0x93])) {
        arg0[0x95] = 0xFF;
        arg0[0x96] = ~arg0[0x93];
        arg0[5]++;
    }
    func_8002D9EC(arg0, 0x10, 0x10);
}
