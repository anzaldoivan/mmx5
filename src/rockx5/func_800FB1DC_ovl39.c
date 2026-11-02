#include "types.h"

extern u8* func_8002D0E4(void);
extern int func_8002D6FC();
extern s32 func_8002DF78(void);
extern s32 func_8002DFB0(void);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);
extern u8 D_800FEB2C_ovl39[];

void func_800FB1DC_ovl39(u8* a0) {
    u8* q;
    u8* o;
    u8* p;
    u8* b;
    s32 i;
    s32 d;
    u8 t;

    *(u16*)(a0 + 0x42) &= 0x7FFF;
    if (*(s8*)(a0 + 0x84) == 0) {
        if (*(s8*)(a0 + 2) == 0) {
            p = *(u8**)(a0 + 0x7C);
            t = p[7] & 0x10;
        } else {
            p = *(u8**)(a0 + 0x7C);
            t = p[7] & 1;
        }
        p[7] = t;
        b = *(u8**)(a0 + 0x7C);
        b += *(s8*)(a0 + 2);
        b[0x8D] = 0;
        if ((*(u8**)(a0 + 0x7C))[0x8C] == 0) {
            (*(u8**)(a0 + 0x7C))[0x8C] = (func_8002DF78() & 1) + 2;
        }
        func_8002D6FC(a0);
        return;
    }
    q = a0 + 0x7C;
    if (!(a0[0x84] & 0xF)) {
        for (i = 0; i < 6; i++) {
            o = func_8002D0E4();
            if (o != 0) {
                o[0] = 0x21;
                o[1] = 4;
                o[2] = 0;
                o[4] = 0;
                o[5] = 0;
                o[6] = 0;
                if (a0[0x8A] == 0) {
                    d = func_8002DFB0() % 160 - 0x50;
                    *(s16*)(o + 0xA) = *(s16*)(a0 + 0xA) + d;
                    d = func_8002DFB0() % 96 - 0x30;
                    *(s16*)(o + 0xE) = *(s16*)(a0 + 0xE) + d;
                } else {
                    d = func_8002DFB0() % 96 - 0x30;
                    *(s16*)(o + 0xA) = *(s16*)(a0 + 0xA) + d;
                    *(s16*)(o + 0xE) =
                        *(s16*)(a0 + 0xE) + func_8002DFB0() % 160 - 0x20;
                }
                o[0x15] = 0;
                o[0x14] = 0;
                o[0x16] = 1;
            }
        }
    }
    a0[3] ^= 1;
    q[8] = a0[0x84] - 1;
    if (*(s8*)(q + 8) == 0) {
        if (a0[0x8A] == 1) {
            *(s16*)(a0 + 0xE) += 0x30;
        }
        a0[3] = 0;
        func_8004D4F4(6, D_800FEB2C_ovl39, a0);
        func_80054440(a0, 0x16);
    }
}
