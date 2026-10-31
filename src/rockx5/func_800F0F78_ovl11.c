#include "types.h"

extern u8* func_8002D1A4();
extern s8 D_800D1C44;
extern u8 D_800F976C_ovl11[];
extern u8 D_800F9854_ovl11[];

void func_800F0F78_ovl11(u8* arg0) {
    u8* o;

    o = func_8002D1A4();
    if (o != 0) {
        o[0] = 0x41;
        o[1] = 0x1E;
        if (*(s8*)(arg0 + 2) == 2) {
            o[2] = D_800F976C_ovl11[*(s32*)(arg0 + 0x84)];
        } else {
            o[2] = (u8)D_800D1C44 ^ (arg0[0x84] & 1);
        }
        if (*(s32*)(arg0 + 0x84) == 3 && D_800D1C44 == 0) {
            o[2]++;
        }
        *(u8**)(o + 0x7C) = arg0;
        *(u16*)(o + 0x42) = *(u16*)(arg0 + 0x42);
        *(u8**)(o + 0x30) = D_800F9854_ovl11;
        *(s32*)(o + 0x3C) = *(s32*)(arg0 + 0x3C);
        *(u16*)(o + 0x40) = *(u16*)(arg0 + 0x40);
        o[0x15] = arg0[0x15];
        o[0x14] = arg0[0x14];
        o[0x16] = 4;
    }
}
