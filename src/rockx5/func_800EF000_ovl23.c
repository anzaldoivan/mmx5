#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern u32* D_80098118;
extern u8 D_800EF2E4_ovl23[];
extern u16 D_800EF304_ovl23[][2];
extern u8 D_800EF324_ovl23[];

void func_800EF000_ovl23(u8* obj) {
    s8 i;

    i = ((s8*)obj)[2];
    *(s16*)(obj + 0x40) = *D_80098118 >> 7;
    *(s32*)(obj + 0x3C) = (s32)D_1F800020.u32s + *D_1F800020.u32s;
    *(u8**)(obj + 0x30) = D_800EF2E4_ovl23;
    *(s16*)(obj + 0x42) = 0x7800;
    obj[0x15] = 0;
    ((s8*)obj)[0x14] = -1;
    *(u16*)(obj + 0xA) = D_800EF304_ovl23[i][0];
    *(u16*)(obj + 0xE) = D_800EF304_ovl23[i][1];
    func_800171E8(obj, D_800EF324_ovl23[i]);
    if ((u8)(obj[2] - 6) < 2) {
        *(s16*)(obj + 0x42) = 0x7804;
    }
    obj[0x16] = 3;
    obj[4]++;
    obj[5] = obj[2];
    if (((s8*)obj)[5] >= 2) {
        obj[3] = 1;
    }
}
