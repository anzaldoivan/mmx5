#include "types.h"

extern s32 func_8002DF78(void);
extern u8* func_8002C938();
extern u8 D_800D1C00[];
extern u8 D_8007C19C[];
extern u8 D_8007C22C[];

void func_8005446C(u8* arg0, s8 arg1, s16 arg2, s16 arg3) {
    u8 row;
    u8 i;
    u32 r;
    u8* p;
    u8* g = D_800D1C00;
    s32 t;

    if ((((s8*)g)[0xC] != 5 || ((s8*)g)[0x1D] != 0) && g[0xA0] < 2) {
        row = arg1 * 6;
        r = func_8002DF78();
        i = 0xFF;
        t = (s32)D_8007C19C;
        do {
            i++;
            r &= 0xFF;
            r = (u16)(r - *(u8*)(i + row + t));
        } while (r < 0x100);
        if (i != 0) {
            p = func_8002C938(r, t);
            if (p != 0) {
                p[0] = 0x21;
                p[1] = 0x2F;
                p[2] = D_8007C22C[i - 1];
                *(s16*)(p + 0xA) = arg2;
                *(s16*)(p + 0xE) = arg3;
                p[0x14] = arg0[0x14];
                *(s32*)(p + 0x10) = 0;
                p[0x82] = 0;
            }
        }
    }
}
