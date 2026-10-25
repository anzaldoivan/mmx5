#include "types.h"

extern void func_800EF9D0_ovl24(void);
extern s8 D_800F5F7A_ovl24;
extern u8 D_800D1C28;

void func_800F04A0_ovl24(u8* arg0) {
    if (D_800F5F7A_ovl24 != 0) {
        func_800EF9D0_ovl24();
    }
    D_800D1C28 = 0x7F;
    arg0[1] = 4;
    arg0[2] = 0;
}
