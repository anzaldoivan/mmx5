#include "types.h"

extern void func_8002385C(s32, s32, s32);
extern D_8009A1F8_99C_t D_8009A1F8;
extern u8* D_800FB960_ovl52;

void func_800FA99C_ovl52(u8* arg0) {
    D_8009A1F8.unkA0 = 1;
    D_8009A1F8.unk60.val += -0x44444;
    if (D_8009A1F8.unk60.val <= 0) {
        D_800FB960_ovl52[0x36] = 0x21;
        D_8009A1F8.unk60.val = 0;
        D_8009A1F8.unk5E = 0;
        D_8009A1F8.unk60.i.hi = 0x200;
        func_8002385C(0x48, 0xFF, 0);
        arg0[1]++;
    }
}
