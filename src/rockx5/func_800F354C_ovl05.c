#include "types.h"

extern void func_80028B18(s32, s32, s32, void*);
extern s32 func_8002B5B4(s32);
extern void func_8002C338(s32, void*, s32);
extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern u8 D_8009A1F8[];
extern u8 D_800F5648_ovl05[];
extern u8 D_800F5668_ovl05[];
extern u8 D_800F58BC_ovl05[];
extern u8 D_800F591C_ovl05[];
extern u8 D_800F593C_ovl05[];
extern u8 D_800F5964_ovl05[];

void func_800F354C_ovl05(u8* arg0) {
    s16 id;
    u8* g;
    u8 t;

    id = ((func_8002B5B4(0x25) << 16) >> 14) + 0x1A;
    *(u16*)(arg0 + 0x7C) += 1;
    g = D_8009A1F8;
    *(s16*)(g + 0x5E) -= 0x10;
    if (*(s16*)(g + 0x5E) + 0x140 < 0x1F0) {
        g[0xA6] = 0;
        g[0x57] = 0;
        *(s16*)(arg0 + 0x7C) = 0;
        arg0[5] = 0;
        arg0[6] = 0;
        func_8002C338(0x61, D_800F5648_ovl05, 1);
        func_8002C338(id, D_800F5668_ovl05, 1);
        D_800F5964_ovl05[1] = 0;
    } else {
        func_8002C3CC(D_800F591C_ovl05, D_800F5648_ovl05, 0x10,
                      *(s16*)(arg0 + 0x7C), *(s16*)(arg0 + 0x7E));
        func_8002C338(0x61, D_800F591C_ovl05, 1);
        func_8002C3CC(D_800F593C_ovl05, D_800F5668_ovl05, 0x10,
                      *(s16*)(arg0 + 0x7C), *(s16*)(arg0 + 0x7E));
        func_8002C338(id, D_800F593C_ovl05, 1);
    }
    arg0[0x81]++;
    if (arg0[0x81] >= 8) {
        arg0[0x81] = 0;
    }
    t = arg0[0x81];
    if (!(t & 1)) {
        func_80028B18(1, 0x1F0, 0x900, D_800F58BC_ovl05 + (t >> 1) * 8);
        D_8009A1F8[0xA0] = 1;
    }
}
