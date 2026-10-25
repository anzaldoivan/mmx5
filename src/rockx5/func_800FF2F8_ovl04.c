#include "types.h"

extern s32 func_8002DF78(void);
extern u8 D_800D1C00[];

void func_800FF2F8_ovl04(u8* arg0) {
    u8* g = D_800D1C00;

    if (((s8*)g)[0x28] == 0) {
        if (arg0[0x8D] == 0 || --arg0[0x8D] == 0) {
            g[0x28] = 1 << (func_8002DF78() & 3);
            arg0[0x8D] = 0x3C;
        }
    }
}
