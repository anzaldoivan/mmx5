#include "types.h"

extern void func_8003D29C(s32, s32);
extern s16 D_8009A0AA;
extern s16 D_8009A21E;

void func_800EFE20_ovl04(u8* arg0) {
    if (D_8009A0AA >= 0xCBD) {
        func_8003D29C(0x14, 0x40);
        D_8009A21E = 0xC80;
        arg0[6]++;
    }
}
