#include "types.h"

extern void func_80016490(s32, s32, void*);
extern s32 func_8002DF78(void);
extern s32 func_8002DFB0(void);
extern void func_8004FF94(s32, s32, s32, s32);
extern u8 D_8009A1F8[];
extern s32 D_8009A420;
extern s32 D_800F96B8_ovl11[];

void func_800EF5A0_ovl11(u8* arg0) {
    u8* base = D_8009A1F8;
    s16 x;
    s16 y;

    x = *(s16*)(base + 0xA);
    y = *(s16*)(base + 0xE);
    arg0[0x1D] = func_8002DFB0() % 4;
    switch (arg0[0x1D]) {
    case 0: // !FAKE: empty case rebalances the case tree (C0286)
        break;
    case 1:
        x += 0xA0;
        break;
    case 2:
        y += 0x78;
        break;
    case 3:
        x += 0xA0;
        y += 0x78;
        break;
    }
    x += func_8002DFB0() % 160;
    y += func_8002DFB0() % 120;
    func_8004FF94(0, x, y, 0xFF);
    if (!(D_8009A420 & 3)) {
        func_80016490(0, D_800F96B8_ovl11[func_8002DF78() & 3], 0);
    }
}
