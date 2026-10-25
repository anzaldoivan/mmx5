#include "types.h"

extern u8 D_800D1599;
extern u8 D_800E805D;
extern u8 D_800E8058[4]; /* CdlATV mix volumes: L->L, L->R, R->R, R->L */

s32 CdMix(u8* vol);

void func_80017E98(u8 vol) {
    D_800E805D = vol;
    if (D_800D1599 == 1) {
        D_800E8058[0] = vol;
        D_800E8058[1] = 0;
        D_800E8058[2] = vol;
        D_800E8058[3] = 0;
    } else {
        D_800E8058[0] = vol >> 1;
        D_800E8058[1] = vol >> 1;
        D_800E8058[2] = vol >> 1;
        D_800E8058[3] = vol >> 1;
    }
    CdMix(D_800E8058);
}
