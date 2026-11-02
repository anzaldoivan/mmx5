#include "types.h"

extern s8 D_800D1C26;
extern u8 D_800F4EC0_ovl24[][2];
extern s32 D_800F4ED0_ovl24[][2];
extern s8 D_800F5F7A_ovl24;

static inline void func_800EF9D0_ovl24_setw(u8* obj, s32 i) {
    ((Obj114*)obj)->w[i] = D_800F4ED0_ovl24[i][0];
}

void func_800EF9D0_ovl24(u8* obj) {
    if (obj[0xC0] >= 4) {
        if (D_800F5F7A_ovl24 == 1) {
            func_800EF9D0_ovl24_setw(obj, D_800D1C26 - 1);
        } else if (D_800F5F7A_ovl24 == 2) {
            func_800EF9D0_ovl24_setw(obj, D_800D1C26 + 7);
        }
        if (obj[0xC0] >= 8) {
            if (D_800F5F7A_ovl24 == 1) {
                func_800EF9D0_ovl24_setw(obj,
                                         D_800F4EC0_ovl24[D_800D1C26 - 1][0]);
                return;
            }
            if (D_800F5F7A_ovl24 == 2) {
                func_800EF9D0_ovl24_setw(obj,
                                         D_800F4EC0_ovl24[D_800D1C26 - 1][1]);
            }
        }
    }
}
