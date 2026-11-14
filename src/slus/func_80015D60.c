/* Adapted from mmx6 @a8f96d1 src/SLUS_013.95/8001651C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"

extern void LoadImage(void*, void*);
extern Ovl50Pos D_800E5A50;
extern u8 D_800E5A58[];
extern u8 D_800E5208;
extern u8 D_800D5208[][0x800];

void func_80015D60(void) {
    u16* p;
    u8* t;
    u8* q;
    s32 o;

    D_800E5A50.unk4 = 0x40;
    t = D_800E5A58;
    o = D_800E5208 * 0xC;
    q = t + 4;
    t = 0;
    p = (u16*)(o + q);
    D_800E5A50.unk6 = 0x10;
    D_800E5A50.unk0 = p[1];
    D_800E5A50.unk2 = p[0];
    LoadImage(&D_800E5A50, D_800D5208[D_800E5208]);
}
