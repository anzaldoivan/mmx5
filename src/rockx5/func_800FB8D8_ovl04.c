#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_8002A600(s32, s32, s32);
extern s32 func_8002DF78(void);
extern u8* func_8002D27C(void);
extern u16 D_8009A22C;
extern s32 D_8009A420;

extern u8 D_800D1C00[];

void func_800FB8D8_ovl04(u8* o) {
    s16 y;
    u32 r;
    u8* s;
    u8* p;
    s32 k;

    o[0x8D]++;
    *(u16*)(o + 0xA) -= 1;
    if ((u8)(o[0x8D] % 40) == 0) {
        func_80016490(2, 0x13, o);
    }
    y = *(s16*)(o + 0xA);
    if (y >= 0xC4A) {
        if (D_8009A22C == 0) {
            func_8002A600(0x10, 3, 2);
        }
    } else if (y < 0xC41) {
        p = D_800D1C00;
        do { // !FAKE: loop notes order the base setup before the counter
            o[5]++;
            k = 0x200000;
        } while (0);
        p[0x26] = 1;
        p[0x27] = 0;
        p[0x2A] = 0;
        p[0x28] = 0;
        p[0x29] = 0;
        p[0x2B] = 0;
        *(s32*)(o + 0x84) = k;
        o[0x8C] = 0;
        o[0x8D] = 0x78;
        r = func_8002DF78();
        o[0x91] = 0;
        o[0x90] = 0;
        *(s16*)(o + 0x88) = (u8)(r % 50) + 0x28;
    }
    if (!(D_8009A420 & 7) && (func_8002DF78() & 0x10)) {
        s = func_8002D27C();
        if (s != 0) {
            s[0] = 0x41;
            s[1] = 0x18;
            s[2] = 0;
            *(u8**)(s + 0x50) = o;
        }
    }
}
