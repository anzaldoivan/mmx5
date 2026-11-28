#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
extern u8 D_800750C0[];
extern u8 D_800FA75C_ovl00[];
extern u8 D_800FA77C_ovl00[];

void func_800F0B84_ovl00(u8* obj) {
    *(u8**)(obj + 0x54) = D_800FA75C_ovl00;
    *(u8**)(obj + 0x68) = D_800FA77C_ovl00;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0x8000;
    *(u8**)(obj + 0x58) = D_800750C0;
    obj[6]++;
}
