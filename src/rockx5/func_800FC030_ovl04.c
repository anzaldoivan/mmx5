#include "types.h"

extern s32 func_8002DF78(void);
extern s32 func_8003D29C(s32, s32);
extern void func_800FBA74_ovl04(u8* o);
extern void func_800FBEF8_ovl04(u8* o);
extern u8 D_8009A1F8[];
extern u8 D_800D1C00[];
extern u8 D_80102B30_ovl04[][2];

void func_800FC030_ovl04(u8* o) {
    u8* p;
    u8* q;
    u8* r;
    s32 i;
    s32 t;

    func_800FBEF8_ovl04(o);
    func_800FBA74_ovl04(o);
    p = D_800D1C00;
    if (*(u16*)(p + 0x28) == 0) {
        if (o[0x8D] == 0 || --o[0x8D] == 0) {
            i = func_8002DF78() & 0xF;
            p[0x28] = D_80102B30_ovl04[i][0];
            p[0x29] = D_80102B30_ovl04[i][1];
            o[0x8D] = 0x78;
        }
    }
    r = D_800D1C00;
    if (r[0x26] & 2) {
        func_8003D29C(0x14, 0x40);
        o[5]++;
        o[0x8D] = 0x78;
        o[0x90] = 0x40;
        o[0x91] = 0x40;
    }
    q = D_8009A1F8;
    t = *(s16*)(o + 0x86) - 0x120;
    *(s16*)(o + 0xA) = *(u16*)(q + 0xA) - t;
    *(s16*)(o + 0xE) = *(u16*)(q + 0xE) + 0x58;
}
