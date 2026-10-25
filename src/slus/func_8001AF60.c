/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001B5FC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:func_800192F8, AGPL-3.0; proven shared with X6 by exact signature 9577b76e9365 (see THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32
M2C_UNK CdMix(M2C_UNK*, u32);
#define CdMix ((int (*)(X4_f32 * vol)) CdMix)
extern u32 D_80070C50;
extern M2C_UNK D_800E8184;
#define D_800E8184 (*(X4_f32*)&D_800E8184)
extern s8 D_800D1599;
#define D_800D1599 (*(u8*)&D_800D1599)

M2C_UNK SsSetSerialAttr(M2C_UNK, M2C_UNK, M2C_UNK);
void func_8001AF60(void) {
    s32 temp_v0;
    s32 var_s0;

    ((void (*)())SsSetSerialAttr)(0, 0, 0);
    if (D_800D1599 != 0) {
        var_s0 = D_80070C50;
        if (var_s0 >= 0) {
            do {
                D_800E8184.bytes[0] = var_s0;
                D_800E8184.bytes[1] = 0;
                D_800E8184.bytes[2] = var_s0;
                D_800E8184.bytes[3] = 0;
                CdMix(&D_800E8184);
                var_s0 -= 2;
            } while (var_s0 >= 0);
        }
    } else {
        var_s0 = D_80070C50;
        if (var_s0 >= 0) {
            do {
                temp_v0 = var_s0 / 2;
                D_800E8184.bytes[0] = temp_v0;
                D_800E8184.bytes[1] = temp_v0;
                D_800E8184.bytes[2] = temp_v0;
                D_800E8184.bytes[3] = temp_v0;
                CdMix(&D_800E8184);
                var_s0 -= 2;
            } while (var_s0 >= 0);
        }
    }
}
#undef D_800D1599
#undef D_800E8184
#undef CdMix
