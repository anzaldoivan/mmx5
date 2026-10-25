/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80026ECC.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "addr.h"

extern u32* D_80091D60[2][102];
extern u32 D_80093F78[2][6][17];
extern X4_BackgroundObj D_8009A1F8[3];
extern struct X4_DrawInfo* D_8009E794;
extern u8 D_800D15A0[];
#define D_800D15A0 (*(X4_P_TAG(*)[2][6][17]) & D_800D15A0)

void func_80027D84(s32 arg0) {
    struct X4_DrawInfo* info;
    u32 v;
    s32 buf;
    s32 l;
    u32 i;

    l = arg0 + 3;
    buf = D_1F800000;
    info = D_8009E794;
    for (i = 0; i < 17; i++) {
        v = D_80093F78[buf][arg0][i];
        if (v != 0) {
            v &= 0xFFFFFF; /* !FAKE: redundant pre-mask orders the mask hoist */
            D_800D15A0[buf][arg0][i].tag =
                (D_800D15A0[buf][arg0][i].tag & 0xFF000000) | (v & 0xFFFFFF);
            (*(u32**)((u8*)D_80091D60 + i * 4 + arg0 * 68 + buf * 408))[0] =
                ((*(u32**)((u8*)D_80091D60 + i * 4 + arg0 * 68 +
                           buf * 408))[0] &
                 0xFF000000) |
                ((&info->ot)[D_8009A1F8[arg0].unk4A] & 0xFFFFFF);
            (&info->ot)[D_8009A1F8[arg0].unk4A] =
                ((&info->ot)[D_8009A1F8[arg0].unk4A] & 0xFF000000) |
                ((u32)&D_800D15A0[buf][arg0][i] & 0xFFFFFF);
        }
        v = D_80093F78[buf][l][i];
        if (v != 0) {
            v &= 0xFFFFFF; /* !FAKE: redundant pre-mask orders the mask hoist */
            D_800D15A0[buf][l][i].tag =
                (D_800D15A0[buf][l][i].tag & 0xFF000000) | (v & 0xFFFFFF);
            (*(u32**)((u8*)D_80091D60 + i * 4 + l * 68 + buf * 408))[0] =
                ((*(u32**)((u8*)D_80091D60 + i * 4 + l * 68 + buf * 408))[0] &
                 0xFF000000) |
                ((&info->ot)[D_8009A1F8[arg0].unk4B] & 0xFFFFFF);
            (&info->ot)[D_8009A1F8[arg0].unk4B] =
                ((&info->ot)[D_8009A1F8[arg0].unk4B] & 0xFF000000) |
                ((u32)&D_800D15A0[buf][l][i] & 0xFFFFFF);
        }
    }
}
#undef D_800D15A0
