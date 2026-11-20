#include "types.h"
#include "mmx5/system.h"

extern u8 D_800F9CF4_ovl11[];
extern u8 D_800F9D00_ovl11[];
extern s32 D_800F9CB4_ovl11[];
extern s32 D_800F9CD4_ovl11[];

void func_800F4D44_ovl11(u8* obj) {
    obj[7] = 1;
    switch ((s8)obj[2]) {
    case 0:
        obj[0x47] = random_byte() % 7;
        break;
    case 1:
        obj[0x47] = D_800F9CF4_ovl11[random_byte() % 11];
        break;
    case 2:
        obj[0x47] = random_byte() % 5;
        break;
    case 3:
        obj[0x47] = random_byte() % 3;
        break;
    case 4:
        obj[0x47] = D_800F9D00_ovl11[random_byte() % 11];
        break;
    }
    obj[0x16] = 1;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0x5000;
    *(u16*)(obj + 0x42) &= 0x7FFF;
    *(s32*)(obj + 0x20) = D_800F9CB4_ovl11[random_byte() & 7];
    *(s32*)(obj + 0x24) = D_800F9CD4_ovl11[random_byte() & 7];
    obj[4]++;
}
