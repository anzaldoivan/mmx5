#include "types.h"

void func_8002385C(s32, s32, s32);

void func_800FA5B4_ovl45(Ovl45State* arg0) {
    if (arg0->unk4 == 0) {
        func_8002385C(0x19, 0xFF, 0);
        arg0->unk1++;
    }
}
