#include "types.h"

extern void func_8002385C(s32, s32, s32);

void func_800FAAD0_ovl54(Ovl45State* arg0) {
    if (arg0->unk4 == 0) {
        func_8002385C(0x58, 0xFF, 0);
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
