#include "types.h"

extern s8 D_800D1C1D;
extern void (*D_80101038_ovl07[])(u8*);
void func_800F2988_ovl07(u8* p);

void func_800F28FC_ovl07(u8* p) {
    *(s32*)(p + 0x18) = *(s32*)(p + 0x8);
    *(s32*)(p + 0x1C) = *(s32*)(p + 0xC);
    if (D_800D1C1D >= 1 && D_800D1C1D < 4) {
        D_80101038_ovl07[*(s8*)(p + 4)](p);
    } else if (D_800D1C1D == 4) {
        func_800F2988_ovl07(p);
    }
}
