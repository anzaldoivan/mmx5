#include "types.h"

extern u8 D_80091C44;
extern X4_BackgroundObj D_8009A1F8[3];
extern u8 D_800FBBC4_ovl49[];
extern u8 D_800FB9C4_ovl49[];
extern u8 D_800FBFC4_ovl49[];
extern u8 D_800FBDC4_ovl49[];

void func_8002C3CC(void*, void*, s32, s32, s32);
s32 func_8002C338(s32, void*, s32);

void func_800FA27C_ovl49(Ovl45State* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8[0].x_pos.val = 0x2000000;
        D_8009A1F8[0].y_pos.val = 0x3000000;
        D_8009A1F8[0].unk3 = 1;
        D_8009A1F8[0].pad4C[0] = 1;
        D_8009A1F8[1].x_pos.val = 0;
        D_8009A1F8[1].y_pos.val = 0x3000000;
        D_8009A1F8[1].unk3 = 1;
        D_8009A1F8[1].pad4C[0] = 1;
        D_8009A1F8[2].x_pos.val = 0;
        D_8009A1F8[2].y_pos.val = 0x3000000;
        D_8009A1F8[2].unk3 = 1;
        D_8009A1F8[2].pad4C[0] = 1;
        arg0->unk4 = 0;
        func_8002C3CC(D_800FBBC4_ovl49, D_800FB9C4_ovl49, 0x100, 0, 0x50);
        func_8002C338(0xA0, D_800FBBC4_ovl49, 0x10);
        func_8002C3CC(D_800FBFC4_ovl49, D_800FBDC4_ovl49, 0x100,
                      0x50 - arg0->unk4, 0x50);
        func_8002C338(0xE0, D_800FBFC4_ovl49, 0x10);
        arg0->unk1++;
    }
}
