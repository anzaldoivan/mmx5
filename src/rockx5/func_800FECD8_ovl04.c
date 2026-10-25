#include "types.h"

extern s32 func_8002DF78(void);
extern u8 D_800D1C00[];
extern u8 D_80102B50_ovl04[][2];

void func_800FECD8_ovl04(u8* arg0) {
    u8* g = D_800D1C00;
    s32 i;

    if (*(u16*)(g + 0x28) == 0) {
        if (arg0[0x8D] == 0 || --arg0[0x8D] == 0) {
            i = func_8002DF78() & 0xF;
            g[0x28] = D_80102B50_ovl04[i][0];
            g[0x29] = D_80102B50_ovl04[i][1];
            arg0[0x8D] = 0x3C;
        }
    }
}
