#include "types.h"

extern s32 D_8009A1F8[];
void func_8002385C(s32, s32, s32);

void func_800FA918_ovl54(Ovl45State* s) {
    D_8009A1F8[23] -= 0x40000;
    if (++s->unk4 >= 0x34) {
        ((s16*)&D_8009A1F8[23])[1] = 0x230;
        s->unk4 = 0;
        s->unk1++;
        func_8002385C(0x57, 0xFF, 0);
    }
}
