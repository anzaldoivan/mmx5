/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80018B60.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:func_80016E84, AGPL-3.0; proven shared with X6 by exact signature adc4ba01bdcd (see THIRD_PARTY.md). */
#include "types.h"
int VSync(int mode);
extern u8 D_800E8088;
#define D_800E8088 (*(u8(*)[]) & D_800E8088)
extern s8 D_800E805E;
extern s32 D_800E8060;

#define M2C_UNK s32
s8 func_80066D58(M2C_UNK, u8*);
s32 CdControl(M2C_UNK, M2C_UNK, u8*);
void func_80018258(void) {

    u8 sp10;

    if (((int (*)())func_80066D58)(1, 0) == 0x02) {
        sp10 = 0x80 | 0x40 | 0x08;
        if (((int (*)())CdControl)(0x0e, &sp10, &D_800E8088) != 0) {
            VSync(3);
            D_800E8060 = 6;
            if (D_800E8088[0] & 0x10) {
                D_800E805E = 1;
            }
        }
    }
}
#undef D_800E8088
