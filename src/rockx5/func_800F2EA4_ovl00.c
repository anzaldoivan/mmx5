#include "types.h"

extern u8* func_8002D1A4();
extern s32 D_800FAC44_ovl00;

void func_800F2EA4_ovl00(u8* arg0, u8 arg1) {
    u8* obj = func_8002D1A4();

    if (obj != 0) {
        obj[0] = 0x41;
        obj[1] = 1;
        obj[2] = arg1;
        *(u8**)(obj + 0x7C) = arg0;
        *(u16*)(obj + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32**)(obj + 0x30) = &D_800FAC44_ovl00;
        *(s32*)(obj + 0x3C) = *(s32*)(arg0 + 0x3C);
        *(u16*)(obj + 0x40) = *(u16*)(arg0 + 0x40);
        obj[0x15] = arg0[0x15];
        obj[0x14] = arg0[0x14];
        obj[0x16] = 4;
    }
}
