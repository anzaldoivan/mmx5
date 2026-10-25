#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern u8 D_8009A1F8[];

void func_800FA588_ovl44(Ovl45State* arg0) {
    u8* p = D_8009A1F8;

    *(s32*)(p + 0xC) += 0xC0000;
    arg0->unk4++;
    if (arg0->unk4 >= 10) {
        *(s16*)(p + 0xE) = 0xF8;
        func_8002385C(0x12, 0xFF, 0);
        arg0->unk1++;
    }
}
