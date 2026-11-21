#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/ovl06.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_8009A244;
extern signed char D_800D1C0C;
extern u8 D_800FF1CC_ovl06[];
extern u8 D_800FF1D0_ovl06[];
extern u8 D_800FF508_ovl06[];
extern u8 D_800FF518_ovl06[];
extern u8 D_800FF528_ovl06[];
extern u8 D_800FF538_ovl06[];

void func_800F9020_ovl06(u8* obj) {
    u8* p;

    obj[0x9A] = 0;
    obj[0x60] = 5;
    *(u8**)(obj + 0x54) = D_800FF1D0_ovl06;
    *(u8**)(obj + 0x50) = D_800FF1CC_ovl06;
    if (obj[0x15] == 0) {
        if (D_800D1C0C != 0xC) {
            func_80028B18(0, 0x11B0, 0x10, D_800FF508_ovl06);
        } else {
            func_80028B18(0, (s16)(D_800FF94C_ovl06 + 0x11B0),
                          (s16)(D_800FF94E_ovl06 + 0x10), D_800FF528_ovl06);
        }
    } else if (D_800D1C0C != 0xC) {
        func_80028B18(0, 0x1300, 0x10, D_800FF518_ovl06);
    } else {
        func_80028B18(0, (s16)(D_800FF94C_ovl06 + 0x1300),
                      (s16)(D_800FF94E_ovl06 + 0x10), D_800FF538_ovl06);
    }
    p = D_1F80004C.bytes;
    D_8009A244 = 1;
    p[0x8A] = 1;
    set_animation(obj, 4);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0x30000;
    *(s32*)(obj + 0x2C) = 0;
    obj[6]++;
}
