#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_80028B18(s32, s32, s32, void*);
extern s32 func_8003D2C4(void);
extern u8 D_800FB45C_ovl09[];

void func_800F86DC_ovl09(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        func_80016490(0, 0xE, 0);
        *(s16*)(obj + 0x7C) = 2;
    }
    if (++*(s8*)(obj + 0x5C) == 0x78) {
        func_80028B18(0, 0x660, 0x870, D_800FB45C_ovl09);
        func_80028B18(0, 0x6B0, 0x870, D_800FB45C_ovl09 + 8);
        func_80028B18(0, 0x700, 0x870, D_800FB45C_ovl09 + 0x10);
        func_80028B18(0, 0x750, 0x870, D_800FB45C_ovl09 + 0x18);
        func_8003D2C4();
        obj[5] = 2;
        obj[6] = 0;
    }
}
