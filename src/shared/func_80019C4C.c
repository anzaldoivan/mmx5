/* Shared body (DK-5), from the banked draft of func_80019C4C by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80022E44.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/14A60.c:func_80024260, AGPL-3.0; proven shared with X6 by exact signature ce7e7513ad74 (see THIRD_PARTY.md). */
#include "types.h"
#include "addr.h"
extern X4_P_TAG* D_80091C50[2][4][8];
extern X4_P_TAG* D_80093E70[2][4][8];
extern struct X4_DrawInfo* D_8009E794;
#define M2C_UNK s32
extern M2C_UNK D_800D1F20;
#define D_800D1F20 (*(s8(*)[4]) & D_800D1F20)

void DEDUP_NAME(void) {
    u32 buffer;
    u32 i;
    u32 j;
    u32* otag;
    X4_P_TAG* p;
    u32 a;

    buffer = D_1F800000;

    for (i = 0; i < 4; i++) {
        otag = &D_8009E794->ot + D_800D1F20[i];

        for (j = 0; j < 8; j++) {
            if (D_80093E70[buffer][i][j] != ((void*)0)) {
                p = D_80091C50[buffer][i][j];
                /* setaddr(p, getaddr(otag)); setaddr(otag, D_80093E70[..]) */
                a = ((X4_P_TAG*)otag)->tag & 0xFFFFFF;
                p->tag = (p->tag & 0xFF000000) | a;
                ((X4_P_TAG*)otag)->tag =
                    (((X4_P_TAG*)otag)->tag & 0xFF000000) |
                    ((u32)D_80093E70[buffer][i][j] & 0xFFFFFF);
            }
        }
    }
}
#undef D_800D1F20
