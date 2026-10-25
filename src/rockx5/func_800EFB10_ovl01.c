#include "types.h"

extern s32 func_8003D2C4(void);
extern s16 D_8009A1F8[];

void func_800EFB10_ovl01(u8* arg0) {
    if (D_8009A1F8[5] == D_8009A1F8[0x13]) {
        func_8003D2C4();
        arg0[4]++;
    }
}
