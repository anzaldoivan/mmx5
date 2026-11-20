#include "types.h"

extern void func_8002C1C8(void);
extern void func_800F2E3C_ovl03(s32);
extern s8 D_8009A0A2;
extern Obj8002CD14 D_800C6A10[];
extern u8 D_800FA238_ovl03;

void func_800F2AE0_ovl03(u8* a0) {
    Obj8002CD14* p;
    s32 i;
    s32 mask;

    a0[0x7D]++;
    if (a0[0x7D] >= 10) {
        func_8002C1C8();
        (&D_8009A0A2)[1] = 1;
        func_800F2E3C_ovl03(0);
        mask = ~8;
        D_800FA238_ovl03 = 0;
        p = D_800C6A10;
        for (i = 0x3F; i >= 0; i--, p++) {
            if (p->active != 0 && ((s8*)p)[1] == (s8)a0[1]) {
                p->active &= mask;
            }
        }
        a0[6]++;
    }
}
