#include "types.h"

extern s32 func_8002A600(s32, s32, s32);
extern u8* func_8002D27C(void);
extern s32 func_8003D29C(s32, s32);
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];

void func_800EEDEC_ovl01(u8* arg0) {
    u8* g;
    u8* s;
    u8* g0;
    u8* s0;
    u8* p;

    s0 = D_8009A1F8;
    if (*(s16*)(s0 + 0x5E) == 0x100) {
        g0 = D_8009A0A0;
        if (g0[0xF7] == 0) {
            arg0[0x18]++;
            if (arg0[0x18] & 1) {
                p = func_8002D27C();
                if (p != 0) {
                    p[0] = 0x41;
                    p[1] = 8;
                    p[2] = arg0[0x18] & 2;
                }
            }
        }
    }
    g = D_8009A0A0;
    if (*(s16*)(g + 0xA) >= 0x1CF0) {
        func_8003D29C(0x14, 0x40);
        arg0[5]++;
    }
    if (g[0xF7] == 0) {
        s = D_8009A1F8;
        if (*(s16*)(s + 0x2A) == *(s16*)(s + 0x28)) {
            if (--arg0[0x1C] == 0) {
                func_8002A600(0x30, 2, 1);
                arg0[0x1C] = 0xA0;
            }
        } else {
            *(s16*)(s + 0x34) = 0;
        }
    }
}
