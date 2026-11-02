#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_80028A20(s32, s32, s32, u8*);
extern u8* func_8002C938();
extern void func_8003B65C(u8*);
extern u8 D_8009A0A0[];
extern u8 D_8009A1F8[];
extern s8 D_800D1C26;
extern u8 D_80100DBC_ovl04[];
extern s16 D_80102FD4_ovl04;

void func_800EF390_ovl04(u8* obj) {
    u8* g = D_8009A1F8;
    u8* p;
    s32 t;

    t = *(u16*)(g + 0x62) + 1;
    *(s16*)(g + 0x62) = t;
    D_80102FD4_ovl04--;
    if ((s16)t >= 0x100) {
        func_80016490(5, 0x14, 0);
        p = func_8002C938();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x1E;
            p[2] = 0x10;
        }
        D_800D1C26 = 0;
        func_8003B65C(D_8009A0A0);
        obj[6]++;
    }
    if (++obj[0x1C] >= 0x18) {
        obj[0x1C] = 0;
    }
    if (obj[0x1C] % 6 == 0) {
        func_80028A20(1, 0x370, 0xF0,
                      D_80100DBC_ovl04 + (u8)(obj[0x1C] / 6) * 8);
    }
}
