#include "types.h"

extern void func_8002C3CC(void*, void*, s32, s32, s32);
extern s32 func_8002C338(s32, void*, s32);
extern u8 D_800FC040_ovl58[];
extern u8 D_800FBE40_ovl58[];
extern u8 D_8009A1F8[];

void func_800FB304_ovl58(UnkObj* arg0) {
    u8* p = D_8009A1F8;

    p[0xAB] = 1;
    *(s16*)(p + 0xB2) = 0;
    *(s16*)(p + 0xB6) = 0x400;
    p[0xF4] = 1;
    func_8002C3CC(D_800FC040_ovl58, D_800FBE40_ovl58, 0x100, 0x3C - arg0->unk4,
                  0x3C);
    func_8002C338(0xD0, D_800FC040_ovl58, 0x10);
    arg0->unk1++;
}
