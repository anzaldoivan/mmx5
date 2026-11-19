#include "types.h"

extern s32 func_8002A600(s32, s32, s32);
extern u8 D_8009A197;
extern u8 D_8009A1F8[];

void func_800EF838_ovl01(u8* arg0) {
    u8* p = D_8009A1F8;
    s32 t;
    s32 u;
    u8* q;

    if (*(s16*)(p + 0x5E) < *(s16*)(arg0 + 0x16)) {
        t = arg0[0x18] + 1;
        arg0[0x18] = t;
        if ((s8)t >= 2) {
            p[0xA0] = 1;
            *(s16*)(p + 0x5E) += 0xE00;
            arg0[5]++;
        }
    }
    if (D_8009A197 == 0) {
        q = D_8009A1F8;
        if (*(s16*)(q + 0x2A) == *(s16*)(q + 0x28)) {
            u = arg0[0x1C] - 1;
            arg0[0x1C] = u;
            if ((u & 0xFF) == 0) {
                func_8002A600(0x30, 2, 1);
                arg0[0x1C] = 0xA0;
            }
        } else {
            *(s16*)(q + 0x34) = 0;
        }
    }
}
