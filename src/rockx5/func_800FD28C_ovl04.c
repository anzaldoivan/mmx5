#include "types.h"

extern s32 func_8002DF78(void);
extern void func_800FCF68_ovl04(u8*, s32);
extern void func_800FD0EC_ovl04(u8*);
extern void func_8003D29C(s32, s32);
extern u8 D_800D1C00[];
extern s32 D_8009A420;
extern s32 D_80102C1C_ovl04[][4];
extern u8 D_8009A1F8[];
extern u8 D_8010309C_ovl04[];
extern u8* D_80103094_ovl04[];

void func_800FD28C_ovl04(u8* o) {
    u8* p = D_800D1C00;
    s32 i;
    u32 r;
    u8* q;

    if (*(s8*)(p + 0x28) == 0) {
        if (o[0x8D] == 0 || --o[0x8D] == 0) {
            *(s8*)(p + 0x28) = 1 << (func_8002DF78() & 3);
            o[0x8D] = 60;
        }
    }
    if (*(s16*)(o + 0x88) == 0 || --*(s16*)(o + 0x88) == 0) {
        if ((D_8009A420 & 7) == 0) {
            if (*(s8*)(o + 0x90) == 0) {
                o[0x91] = func_8002DF78() & 3;
            }
            func_800FCF68_ovl04(
                o, D_80102C1C_ovl04[*(s8*)(o + 0x91)][*(s8*)(o + 0x90)]);
            if (++*(s8*)(o + 0x90) >= 4) {
                r = func_8002DF78();
                o[0x90] = 0;
                *(s16*)(o + 0x88) = (u8)(r % 26) + 20;
            }
        }
    }
    func_800FD0EC_ovl04(o);
    if (D_800D1C00[0x26] & 2) {
        func_8003D29C(20, 0);
        for (i = 0; i < 2; i++) {
            D_80103094_ovl04[i] = 0;
            D_8010309C_ovl04[i] = i * 10;
        }
        o[5]++;
    }
    q = D_8009A1F8;
    *(u16*)(o + 0xE) = *(u16*)(q + 0xE) + 0xB0;
}
