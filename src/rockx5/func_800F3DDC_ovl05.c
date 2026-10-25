#include "types.h"

extern void func_8002A600(s32, s32, s32);
extern void func_80016490(s32, s32, void*);
extern u8 D_8009A1F8[];
extern s16 D_800F595C_ovl05;
extern s16 D_800F595E_ovl05;

void func_800F3DDC_ovl05(u8* arg0) {
    u8* p;
    s32 t;

    func_8002A600(0x30, 3, 2);
    p = D_8009A1F8;
    t = *(u16*)(p + 0xA) - 0x10;
    *(s16*)(arg0 + 0xA) = t;
    t = 1;
    p[0x57] = t;
    p[0xA6] = 0;
    p[0x98] = 0;
    *(s16*)(p + 0x5E) = D_800F595C_ovl05 - *(s16*)(arg0 + 0xA);
    *(s16*)(p + 0x62) = D_800F595E_ovl05 - *(s16*)(arg0 + 0xE);
    *(s16*)(arg0 + 0x7C) = 0;
    arg0[0x81] = 0;
    arg0[6]++;
    func_80016490(2, 0x1A, arg0);
}
