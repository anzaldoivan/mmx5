#include "types.h"

extern s32 func_8003D29C(s32, s32);
extern s16 D_8009A0AA;
extern X4_BackgroundObj D_8009A1F8[3];

void func_800EFF84_ovl04(u8* arg0) {
    if (D_8009A0AA >= 0x12D1) {
        func_8003D29C(0x14, 0x40);
        D_8009A1F8[0].unk26 = 0x12C0;
        D_8009A1F8[0].unk24 = 0x12C0;
        arg0[6]++;
    }
}
