/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8001B428.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:func_80019100, AGPL-3.0; proven shared with X6 by exact signature f2a2862257fa (see THIRD_PARTY.md). */
#include "types.h"
typedef unsigned long X4_u_long;
#define M2C_UNK s32
M2C_UNK LoadImage(M2C_UNK*, M2C_UNK*);
void StCdInterrupt(void);
extern void DecDCTout(X4_u_long* buf, int size);
extern s32 D_800E8118;
extern volatile s32 D_800E8174;
extern s32 D_800E8154;
extern Ovl50Pos D_800E8158;
extern u32* D_800E8160;
extern s32 D_800E8164;
extern s32 D_800E8168;
extern u32 D_800E816C;
extern u32 D_800E8170;
extern s32 D_800EA95C;

void func_8001AD8C(void) {
    u32* temp_a0;

    D_800E816C += 1;
    if (D_800EA95C != 0) {
        StCdInterrupt();
        D_800EA95C = 0;
    }
    if (D_800E8154 == 0) {
        LoadImage(&D_800E8158, D_800E8160);
    }
    if ((u32)D_800E816C < (u32)D_800E8170) {
        D_800E8158.unk0 += (D_800E8118 ? 0x18 : 0x10);
        temp_a0 = &D_800E8160[D_800E8164];
        D_800E8160 = temp_a0;
        DecDCTout(temp_a0, D_800E8168);
        D_800E8174 = 1;
        return;
    }
    D_800E8174 = 0;
}
