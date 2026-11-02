#include "types.h"

extern u8* func_8002D0E4(void);
extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern s32 func_8002DFB0(void);
extern u8 D_8009A0B4;

void func_800F4538_ovl11(u8* arg0) {
    u8* p;
    s32 i;
    s32 a;
    s32 b;
    s32 c;
    s32 e;
    s32 g;
    s32 h;

    i = 11;
    if ((*(s8**)(arg0 + 0x7C))[7] == *(s8*)(arg0 + 2)) {
        do {
            p = func_8002D27C();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x31;
                p[0x15] = func_8002DF78() & 0x40;
                p[2] = 4;
                if (*(s8*)(arg0 + 2) == 5) {
                    a = func_8002DFB0() % 192 - 0x60;
                    *(s16*)(p + 0xA) = *(s16*)(arg0 + 0xA) + a;
                } else {
                    a = func_8002DFB0() % 288 - 0x90;
                    *(s16*)(p + 0xA) = *(s16*)(arg0 + 0xA) + a;
                }
                b = func_8002DFB0();
                g = b % 64 - 0x40;
                *(s16*)(p + 0xE) = *(s16*)(arg0 + 0xE) + g;
                *(s16*)(p + 0x40) = *(s16*)(arg0 + 0x40);
                *(s32*)(p + 0x3C) = *(s32*)(arg0 + 0x3C);
                *(s16*)(p + 0x42) = *(s16*)(arg0 + 0x42);
                p[0x14] = D_8009A0B4;
            }
            p = func_8002D0E4();
            if (p != 0) {
                p[0] = 0x21;
                p[1] = 4;
                p[2] = 0;
                p[4] = 0;
                p[5] = 0;
                p[6] = 0;
                if (*(s8*)(arg0 + 2) == 5) {
                    c = func_8002DFB0() % 192 - 0x60;
                    *(s16*)(p + 0xA) = *(s16*)(arg0 + 0xA) + c;
                } else {
                    c = func_8002DFB0() % 288 - 0x90;
                    *(s16*)(p + 0xA) = *(s16*)(arg0 + 0xA) + c;
                }
                e = func_8002DFB0();
                h = e % 64 - 0x20;
                *(s16*)(p + 0xE) = *(s16*)(arg0 + 0xE) + h;
                p[0x15] = 0;
                p[0x14] = 0;
                p[0x16] = 1;
            }
            i--;
        } while (i >= 0);
        arg0[3] = 0;
        arg0[4] = 2;
    }
}
