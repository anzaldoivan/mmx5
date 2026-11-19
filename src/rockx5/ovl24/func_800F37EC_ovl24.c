#include "types.h"

extern s8 D_8009A424;
void func_8001E6AC(void);
void func_80012EAC(void);

void func_800F37EC_ovl24(u8* a0) {
    s32 i;
    u8* p;
    u8 v;

    if (D_8009A424 == 0) {
        if (((s8*)a0)[3] == 0) {
            v = a0[0x194];
            if (v == 0xFF) {
                a0[0] = 3;
            } else {
                a0[0] = 0x13;
                a0[0x1D] = v;
            }
            a0[1] = 0;
            a0[2] = 0;
            a0[3] = 0;
        } else {
            func_8001E6AC();
            func_80012EAC();
        }
        i = 15;
        p = a0 + 0x35;
        for (; i >= 0; i--) {
            *p-- = 0;
        }
    }
}
