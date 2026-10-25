#include "types.h"

extern void func_8002C1C8(void);
extern void func_8002385C(s32, s32, s32);
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern s32 D_80093DE0;

void func_800FB1E8_ovl56(UnkObj* arg0) {
    arg0->unk4++;
    if (arg0->unk4 >= 0x14) {
        arg0->unk4 = 0;
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        D_80093DE0 = 0xFFFF;
        func_8002385C(0x63, 0xFF, 0);
        arg0->unk1++;
    }
}
