#include "types.h"

extern u8 D_800D1599;
extern u32 D_80070C50;
extern u8 D_800E8184[4]; /* CdlATV mix volumes: L->L, L->R, R->R, R->L */

s32 CdMix(u8* vol);

void func_8001B268(u32 vol) {
    D_80070C50 = vol;
    if (D_800D1599) {
        D_800E8184[0] = vol;
        D_800E8184[1] = 0;
        D_800E8184[2] = vol;
        D_800E8184[3] = 0;
    } else {
        D_800E8184[0] = vol >> 1;
        D_800E8184[1] = vol >> 1;
        D_800E8184[2] = vol >> 1;
        D_800E8184[3] = vol >> 1;
    }
    CdMix(D_800E8184);
}
