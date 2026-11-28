#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/ovl26.h"
#include "addr.h"

#define D_800FA634_ovl26_as_Blk20 (*(Blk20*)D_800FA634_ovl26)

extern void func_8002C1C8(void);
extern u8 D_800D50DC;
extern u8 D_8009A42C;
extern u8 D_80093E66;
extern s32 D_80093DD0[];
extern u16 D_800F8BF4_ovl26[][2];

void func_800EEAD8_ovl26(u8* arg0) {
    u8* p;
    s32 one;
    s32 n;

    D_800D50DC = 1;
    D_8009A42C = 1;
    D_80093E66 = 1;
    func_8002C1C8();
    one = 1;
    D_80093DD0[2] |= 0x10000000;
    n = 0x1F;
    *(s16*)(arg0 + 0x16) = 0;
    D_800D50DE = n;
    D_8009A42E = 0x3E0;
    D_80093E68 = 0x7C00;
    p = D_8009A1F8.u;
    p[0xF4] = one;
    p[0xAB] = 0;
    *(u16*)(p + 0xB2) = D_800F8BF4_ovl26[0][0];
    *(u16*)(p + 0xB6) = D_800F8BF4_ovl26[0][1];
    D_800FA634_ovl26_as_Blk20 = *(Blk20*)(D_1F800028 + 0x840);
    arg0[6]++;
}
#undef D_800FA634_ovl26_as_Blk20

extern u8 D_800FA654_ovl26[];
extern void func_8002C1C8(void);
extern void func_8002C3CC(void*, void*, s32, s32, s32);

void func_800EEC20_ovl26(u8* arg0) {
    u8* p;

    if ((s16)(++*(s16*)(arg0 + 0x16) % 3) == 0) {
        p = (u8*)&D_8009A1F8.t;
        p[0xAB] = 1;
        D_800D50DE--;
        D_8009A42E -= 0x20;
        D_80093E68 -= 0x400;
        func_8002C3CC(D_800FA654_ovl26, D_800FA634_ovl26, 0x10,
                      0x1F - D_800D50DE, 0x1F);
        ((s32(*)())load_palette)(0x42, D_800FA654_ovl26, 1);
        if (D_800D50DE == 0) {
            arg0[6]++;
            func_8002C1C8();
            p[0x57] = 0;
            ((s32(*)())load_palette)(0x42, D_800FA634_ovl26, 1);
        }
    }
}
