#include "types.h"
#include "mmx5/graphics.h"

extern u8 D_800767E0[];
extern u8 D_80101014_ovl07[];
extern u8 D_80101018_ovl07[];
extern u8 D_80101028_ovl07[];
extern u8 D_8010102C_ovl07[];

void func_800F2DAC_ovl07(u8* obj) {
    *(u8**)(obj + 0x58) = D_800767E0;
    if (*(s8*)(obj + 0x66) > 0) {
        set_animation(obj, 9);
        *(u8**)(obj + 0x54) = D_80101028_ovl07;
        *(u8**)(obj + 0x68) = D_80101014_ovl07;
    } else {
        set_animation(obj, 10);
        *(u8**)(obj + 0x54) = D_8010102C_ovl07;
        *(u8**)(obj + 0x68) = D_80101018_ovl07;
    }
    *(u32*)(obj + 0x50) = 0;
    obj[6]++;
}
