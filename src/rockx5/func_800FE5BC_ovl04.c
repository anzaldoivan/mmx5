#include "types.h"

extern s32 func_8002DF78(void);
extern u8 D_800D1C00[];
extern u8 D_80102B10_ovl04[];
extern u8 D_80102AF0_ovl04[];

void func_800FE5BC_ovl04(u8* arg0) {
    u8* g = D_800D1C00;
    s32 r;

    if (*(u16*)(g + 0x28) == 0) {
        if (arg0[0x8D] != 0) {
            arg0[0x8D]--;
            if (arg0[0x8D] != 0) {
                return;
            }
        }
        r = func_8002DF78() & 0xF;
        if ((g[0x2A] & 3) == 3) {
            g[0x28] = D_80102B10_ovl04[r * 2];
            g[0x29] = (&D_80102B10_ovl04[r * 2])[1];
        } else {
            g[0x28] = D_80102AF0_ovl04[r * 2];
            g[0x29] = (&D_80102AF0_ovl04[r * 2])[1];
        }
        arg0[0x8D] = 0x78;
    }
}
