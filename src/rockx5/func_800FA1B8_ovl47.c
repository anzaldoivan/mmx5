#include "types.h"

extern u8 D_8009A1F8[];

extern void func_8002385C(s32, s32, s32);

void func_800FA1B8_ovl47(Ovl45State* arg0) {
    if (arg0->unk4 == 0) {
        func_8002385C(0x20, 0xFF, 0);
        D_8009A1F8[0xAB] = 1;
        *(s32*)(D_8009A1F8 + 0x5C) = 0x300000;
        *(s32*)(D_8009A1F8 + 0x60) = 0;
        D_8009A1F8[0x57] = 1;
        D_8009A1F8[0xA0] = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
