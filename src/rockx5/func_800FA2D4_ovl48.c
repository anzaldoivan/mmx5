#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern u8 D_8009A2A3;

void func_800FA2D4_ovl48(Ovl45State* arg0) {
    if (arg0->unk4 == 0) {
        D_8009A2A3 = 1;
        func_8002385C(0x23, 0xFF, 0);
        arg0->unk1++;
    }
}
