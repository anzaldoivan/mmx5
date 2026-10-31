/* Shared body (DK-5), from the banked draft of func_800F8ED4_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_80028B18(s32, s16, s16, void*);
extern u8 D_8009A244;
extern s8 D_800D1C0C;
extern u8 D_800FF508_ovl06[];
extern u8 D_800FF518_ovl06[];
extern u8 D_800FF528_ovl06[];
extern u8 D_800FF538_ovl06[];
extern u16 D_800FF94C_ovl06;
extern u16 D_800FF94E_ovl06;

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        func_800171E8(obj, 2);
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        if (obj[0x15] == 0) {
            if (D_800D1C0C != 0xC) {
                func_80028B18(0, 0x11B0, 0x10, D_800FF508_ovl06);
            } else {
                func_80028B18(0, D_800FF94C_ovl06 + 0x11B0,
                              D_800FF94E_ovl06 + 0x10, D_800FF528_ovl06);
            }
        } else if (D_800D1C0C != 0xC) {
            func_80028B18(0, 0x1300, 0x10, D_800FF518_ovl06);
        } else {
            func_80028B18(0, D_800FF94C_ovl06 + 0x1300, D_800FF94E_ovl06 + 0x10,
                          D_800FF538_ovl06);
        }
        D_8009A244 = 1;
        obj[6]++;
    }
}
