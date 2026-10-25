#include "types.h"

s32 CdControl(s32, s32, u8*); /* extern */
extern s16 D_800E8090;
extern u8 D_800A51A4;
extern u8 D_800E8088;
extern s32 D_800E8060;
extern s8 D_800E805E;

void func_80017FB4(void) {
    if (D_800E8090 & D_800A51A4) {
        while (CdControl(9, 0, &D_800E8088) == 5) {
        }
        D_800E8060 = 3;
        if (D_800E8088 & 0x10) {
            D_800E805E = 1;
        }
    }
}
