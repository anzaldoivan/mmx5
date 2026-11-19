#include "types.h"
#include "mmx5/globals.h"

extern u8 D_800F9620_ovl26[];
extern u8 D_800F962C_ovl26[];

void func_800F52E8_ovl26(u8* p) {
    animate_object(p);
    if (*(s8*)(p + 0x45) == 1) {
        *(s32*)(p + 0x2C) = 0x1000;
        *(s32*)(p + 0x24) = 0;
        p[0x60] = 0x18;
        *(u8**)(p + 0x68) = D_800F9620_ovl26;
        *(u8**)(p + 0x50) = D_800F962C_ovl26;
        p[6]++;
    }
}
