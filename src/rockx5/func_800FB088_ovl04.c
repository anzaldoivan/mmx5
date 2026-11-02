#include "types.h"

extern s32 rsin(s32);
extern s32 rcos(s32);
extern void func_8004FE6C();
extern void func_8002A600(s32, s32, s32);
extern s32 func_8002DF78(void);
extern u8* func_8002D27C(void);
extern u8 D_8009A1F8[];
extern u16 D_8009A22C;
extern s32 D_8009A420;
extern u8 D_800D1C00[];
extern u8* D_8010308C_ovl04;

void func_800FB088_ovl04(u8* obj) {
    s32 x;
    s32 y;
    u8* p;
    u8* b;

    *(s32*)(obj + 8) += rsin(0x2AA) << 4;
    y = *(s32*)(obj + 0xC) - (rcos(0x2AA) << 4);
    *(s32*)(obj + 0xC) = y;
    if (!(D_8009A420 & 3)) {
        b = D_8009A1F8;
        x = *(s32*)(obj + 8);
        *(s16*)(obj + 0xA) = *(s16*)(b + 0xA) + 0x50;
        *(s16*)(obj + 0xE) = *(s16*)(b + 0xE) + 0x3C;
        func_8004FE6C(obj, 1, 0x60, 0x60, 2);
        *(s32*)(obj + 8) = x;
        *(s32*)(obj + 0xC) = y;
    }
    if (*(s16*)(obj + 0xE) >= 0x5E && D_8009A22C == 0) {
        func_8002A600(0x10, 3, 2);
    }
    if (*(s16*)(obj + 0xE) < 0x69) {
        D_800D1C00[0x2A] |= 8;
        if (D_8010308C_ovl04 != 0) {
            D_8010308C_ovl04[4] = 2;
        }
        obj[5]++;
    }
    if (!(D_8009A420 & 7) && (func_8002DF78() & 0x10)) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x18;
            p[2] = 0;
            *(u8**)(p + 0x50) = obj;
        }
    }
}
