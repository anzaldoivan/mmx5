#include "types.h"

extern s32 func_8002DF78(void);
extern u8 D_800FB600_ovl09[];
extern u8 D_800FB60C_ovl09[];
extern s32 D_800FB5C0_ovl09[];
extern s32 D_800FB5E0_ovl09[];

void func_800F981C_ovl09(u8* obj) {
    obj[7] = 1;
    switch ((s8)obj[2]) {
    case 0:
        obj[0x47] = func_8002DF78() % 7;
        break;
    case 1:
        obj[0x47] = D_800FB600_ovl09[func_8002DF78() % 11];
        break;
    case 2:
        obj[0x47] = func_8002DF78() % 5;
        break;
    case 3:
        obj[0x47] = func_8002DF78() % 3;
        break;
    case 4:
        obj[0x47] = D_800FB60C_ovl09[func_8002DF78() % 11];
        break;
    }
    obj[0x16] = 1;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0x5000;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    *(s32*)(obj + 0x20) = D_800FB5C0_ovl09[func_8002DF78() & 7];
    *(s32*)(obj + 0x24) = D_800FB5E0_ovl09[func_8002DF78() & 7];
    obj[4]++;
}
