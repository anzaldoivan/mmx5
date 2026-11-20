/* Shared body (DK-5), from the banked draft of func_800F8ED4_ovl06 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl06.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_8009A244;
extern s8 D_800D1C0C;
extern u8 D_800FF508_ovl06[];
extern u8 D_800FF518_ovl06[];
extern u8 D_800FF528_ovl06[];
extern u8 D_800FF538_ovl06[];

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        set_animation(obj, 2);
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        if (obj[0x15] == 0) {
            if (D_800D1C0C != 0xC) {
                ((void (*)(s32, s16, s16, void*))func_80028B18)(
                    0, 0x11B0, 0x10, D_800FF508_ovl06);
            } else {
                ((void (*)(s32, s16, s16, void*))func_80028B18)(
                    0, D_800FF94C_ovl06 + 0x11B0, D_800FF94E_ovl06 + 0x10,
                    D_800FF528_ovl06);
            }
        } else if (D_800D1C0C != 0xC) {
            ((void (*)(s32, s16, s16, void*))func_80028B18)(0, 0x1300, 0x10,
                                                            D_800FF518_ovl06);
        } else {
            ((void (*)(s32, s16, s16, void*))func_80028B18)(
                0, D_800FF94C_ovl06 + 0x1300, D_800FF94E_ovl06 + 0x10,
                D_800FF538_ovl06);
        }
        D_8009A244 = 1;
        obj[6]++;
    }
}
