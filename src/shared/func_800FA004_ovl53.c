/* Shared body (DK-5), from the banked draft of func_800FA004_ovl53 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_80091C44;
extern X4_BackgroundObj D_8009A1F8[3];
extern u8 D_800FAF9C_ovl53[];
extern u8 D_800FAD9C_ovl53[];
extern u8 D_800FB39C_ovl53[];
extern u8 D_800FB19C_ovl53[];

void func_8002C3CC(void*, void*, s32, s32, s32);
s32 func_8002C338(s32, void*, s32);
s32 func_80016490(s32, s32, void*);

void DEDUP_NAME(Ovl45State* arg0) {
    if (D_80091C44 == 0) {
        D_8009A1F8[1].x_pos.i.hi = 0;
        D_8009A1F8[1].y_pos.i.hi = 0x100;
        D_8009A1F8[1].unk3 = 1;
        D_8009A1F8[1].pad4C[0] = 1;
        D_8009A1F8[2].x_pos.i.hi = 0;
        D_8009A1F8[2].y_pos.i.hi = 0x100;
        D_8009A1F8[2].unk3 = 1;
        D_8009A1F8[2].pad4C[0] = 1;
        arg0->unk4 = 0;
        func_8002C3CC(D_800FAF9C_ovl53, D_800FAD9C_ovl53, 0x100, 0, 0x1E);
        func_8002C338(0x60, D_800FAF9C_ovl53, 0x10);
        func_8002C3CC(D_800FB39C_ovl53, D_800FB19C_ovl53, 0x100,
                      0x1E - arg0->unk4, 0x1E);
        func_8002C338(0x70, D_800FB39C_ovl53, 0x10);
        func_80016490(2, 0x54, 0);
        arg0->unk1++;
    }
}
