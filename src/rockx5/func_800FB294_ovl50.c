#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern s32 D_8009A1F8[];

void func_800FB294_ovl50(Ovl45State* arg0) {
    D_8009A1F8[0x5C / 4] -= 0xAAAAA;
    arg0->unk4++;
    if (arg0->unk4 >= 30) {
        D_8009A1F8[0x5C / 4] = 0;
        arg0->unk4 = 0;
        func_8002385C(0x42, 0xFF, 0);
        arg0->unk1++;
    }
}
