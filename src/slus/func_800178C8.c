/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80018290.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_UNK s32

M2C_UNK func_80017B5C(u8);
void func_80017D88();
M2C_UNK CdMix(M2C_UNK*, u32);
#define CdMix ((M2C_UNK(*)(M2C_UNK*, u8))CdMix)
extern s32 D_800708B4;
extern void (*D_800708B8[])(void);
extern s8 D_8009A418;
#define D_8009A418 (*(u8*)&D_8009A418)
extern s8 D_800D1599;
#define D_800D1599 (*(u8*)&D_800D1599)
extern u32 D_800E8048;
extern M2C_UNK D_800E8058;
extern u8 D_800E805C;
extern u8 D_800E805D;
extern s8 D_800E805E;
#define D_800E805E (*(u8*)&D_800E805E)
extern s32 D_800E8060;
extern s32 D_800E8064;
extern u8 D_800E8099;
extern s32 D_800E80A4;

s32 func_800178C8(void) {
    u32 temp_v1;
    u8 temp_a1;
    u8 temp_v1_2;
    s32 temp_s;

    if (D_800E80A4 == 2) {
        if (D_800E805E == 0) {
            D_800708B8[D_800E8060]();
            if (D_8009A418 != 0) {
                if (D_800E8048 < 4U) {
                    D_800E8048 = 0;
                    D_800708B4 = 1;
                    func_80017D88();
                    D_8009A418 = 0;
                } else if (D_800708B4 != 0) {
                    D_800708B4 = 0;
                    D_800E8048 = D_800E805D - D_800E8064;
                } else {
                    D_800708B4 = 1;
                }
                temp_a1 = D_800E8048;
                D_800E805D = temp_a1;
                if (D_800D1599 == 1) {
                    ((u8*)&D_800E8058)[0] = temp_a1;
                    ((s8*)&D_800E8058)[1] = 0;
                    ((u8*)&D_800E8058)[2] = temp_a1;
                    ((s8*)&D_800E8058)[3] = 0;
                } else {
                    temp_v1 = temp_a1 >> 1;
                    ((u8*)&D_800E8058)[0] = temp_v1;
                    ((u8*)&D_800E8058)[1] = temp_v1;
                    ((u8*)&D_800E8058)[2] = temp_v1;
                    ((u8*)&D_800E8058)[3] = temp_v1;
                }
                CdMix(&D_800E8058, temp_a1);
            }
            temp_s = D_800D1599;
            temp_v1_2 = temp_s & 0xFF;
            if (D_800E8099 != temp_v1_2) {
                D_800E8099 = temp_s;
                if (temp_v1_2 == 1) {
                    D_800D1599 = temp_v1_2;
                    func_80017B5C(D_800E805C);
                } else {
                    D_800D1599 = 0;
                    func_80017B5C(D_800E805C);
                }
            }
            return 0;
        }
        return -1;
    }
    return -1;
}
#undef D_800D1599
#undef D_8009A418
#undef CdMix
#undef D_800E805E
