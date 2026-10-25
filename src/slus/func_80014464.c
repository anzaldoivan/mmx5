/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80014D50.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/3D88.c:func_800136B0, AGPL-3.0; proven shared with X6 by exact signature 630fc0e04ff1 (see THIRD_PARTY.md). */
#include "types.h"
int CdGetSector(void* madr, int size);
int CdPosToInt(void* p);
extern u8* D_800E5A1C;
extern s32 D_800E5A24;
extern s32 D_800E5A18;
extern u8 D_800E5218[0x800];
extern void D_800E5BF8;

s8 func_80014464(void) {
    s32 temp_v0_2;
    s32 temp_v0_3;
    u32 temp_v0;
    u32 var_v0;

    if ((u32)D_800E5A18 >= 0x801U) {
        CdGetSector(&D_800E5BF8, 3);
        temp_v0_2 = CdPosToInt(&D_800E5BF8);
        if (temp_v0_2 == (D_800E5A24 + 1)) {
            D_800E5A24 = temp_v0_2;
            CdGetSector(D_800E5A1C, 0x200);
            temp_v0 = D_800E5A18 - 0x800;
            D_800E5A18 = temp_v0;
            D_800E5A1C += 0x800;
        } else {
            return -1;
        }
    } else {
        CdGetSector(&D_800E5BF8, 3);
        temp_v0_3 = CdPosToInt(&D_800E5BF8);
        if (temp_v0_3 != (D_800E5A24 + 1)) {
            return -1;
        }
        D_800E5A24 = temp_v0_3;
        CdGetSector(D_800E5A1C, ((u32)(D_800E5A18 + 3) >> 2));
        var_v0 = (u32)(D_800E5A18 + 3) >> 2;
        if (var_v0 != 0x200) {
            var_v0 = CdGetSector(&D_800E5218, 0x200 - var_v0);
        }
        D_800E5A18 = 0;
    }
}
