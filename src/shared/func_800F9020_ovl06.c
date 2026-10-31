/* Shared body (DK-5), from the banked draft of func_800F9020_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80028B18(s32, s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_8009A244;
extern signed char D_800D1C0C;
extern u8 D_800FF1CC_ovl06[];
extern u8 D_800FF1D0_ovl06[];
extern u8 D_800FF508_ovl06[];
extern u8 D_800FF518_ovl06[];
extern u8 D_800FF528_ovl06[];
extern u8 D_800FF538_ovl06[];
extern u16 D_800FF94C_ovl06;
extern u16 D_800FF94E_ovl06;

void DEDUP_NAME(u8* obj) {
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
    func_800171E8(obj, 4);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0x30000;
    *(s32*)(obj + 0x2C) = 0;
    obj[6]++;
}
