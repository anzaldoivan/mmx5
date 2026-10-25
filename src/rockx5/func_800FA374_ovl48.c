#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern s32 D_8009A1F8[];

void func_800FA374_ovl48(Ovl45State* arg0) {
    D_8009A1F8[0x5C / 4] += 0xB3333;
    arg0->unk4++;
    if (arg0->unk4 >= 10) {
        D_8009A1F8[0x5C / 4] = 0x700000;
        func_8002385C(0x24, 0xFF, 0);
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
