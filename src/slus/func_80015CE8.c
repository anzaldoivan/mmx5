/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001668C.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/3D88.c:func_80014140, AGPL-3.0; proven shared with X6 by exact signature 6ba38c1ddd23 (see THIRD_PARTY.md). */
#include "types.h"
typedef unsigned char X4_u_char;
#define CdlPause 0x09
#define NULL ((void*)0)
#define M2C_UNK s32
s32 CdControlB(M2C_UNK, M2C_UNK, u8*);
void (*func_80066D98(void (*func)(X4_u_char, X4_u_char*)))(X4_u_char,
                                                           X4_u_char*);
extern u8* D_800E5BD8;
extern u8 D_8009811C;
extern u8* D_800E5A1C;
extern u8 D_800E5A3D;
s8 func_80014464();

void func_80015CE8(void) {
    if (D_800E5A3D != 0) {
        D_800E5A3D = 0;
        D_800E5A1C = D_800E5BD8;
    }
    if (func_80014464() == -1) {
        func_80066D98(0);
        CdControlB(CdlPause, NULL, NULL);
        D_8009811C = 0x80;
    }
}
