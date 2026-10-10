#include "types.h"

extern s32 D_8009A1F8[];
void func_8002385C(s32, s32, s32);

void func_800FA678_ovl54(Ovl45State* s) {
    D_8009A1F8[2] += 0x20000;
    if (++s->unk4 >= 0x60) {
        func_8002385C(0x55, 0xFF, 0);
        ((s16*)&D_8009A1F8[2])[1] = 0x2C0;
        s->unk1++;
    }
}
