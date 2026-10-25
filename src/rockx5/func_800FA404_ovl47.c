#include "types.h"

extern void func_8002C1C8(void);
extern void func_8002385C(s32, s32, s32);
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern u16 D_80093E68;
extern u16 D_8009A42E;
extern u16 D_800D50DE;

void func_800FA404_ovl47(u8* arg0) {
    D_800D50DE--;
    D_8009A42E -= 0x20;
    D_80093E68 -= 0x400;
    if (D_800D50DE == 0) {
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        func_8002385C(0x22, 0xFF, 0);
        *(s16*)(arg0 + 4) = 0;
        arg0[1]++;
    }
}
