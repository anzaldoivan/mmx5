#include "types.h"

extern void func_8002A5C4(s32, s32, s32);
extern void func_800F5988_ovl00(s32, void*, u8*, s32);
extern s16 D_8009A0AA;
extern u8 D_800FB26C_ovl00[];

void func_800F588C_ovl00(u8* arg0) {
    s32 t;

    t = *(s32*)(arg0 + 0x80) + 1;
    *(s32*)(arg0 + 0x80) = t;
    switch (*(s8*)(arg0 + 2)) {
    case 0:
        *(s32*)(arg0 + 0x80) = t & 0xF;
        if (D_8009A0AA >= *(s16*)(arg0 + 0xA)) {
            *(s32*)(arg0 + 0x2C) = 0x1000;
            func_8002A5C4(0x18, 3, 1);
            arg0[6]++;
        }
        break;
    case 1:
        *(s32*)(arg0 + 0x80) = t & 0x1F;
        if (D_8009A0AA >= 0xB40) {
            *(s32*)(arg0 + 0x2C) = 0x1000;
            func_8002A5C4(0x18, 3, 1);
            arg0[6]++;
        }
        break;
    case 2:
        *(s32*)(arg0 + 0x80) = t & 0x1F;
        if (D_8009A0AA >= 0xBE8) {
            *(s32*)(arg0 + 0x2C) = 0x1000;
            func_8002A5C4(0x18, 3, 1);
            arg0[6]++;
        }
        break;
    }
    if (*(s32*)(arg0 + 0x80) == 0) {
        func_800F5988_ovl00(3, D_800FB26C_ovl00, arg0, 1);
    }
}
