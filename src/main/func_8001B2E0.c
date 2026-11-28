#include "types.h"

extern u8 D_800D1599;
extern u32 D_80070C50;
extern u8 D_800E8184[4]; /* CdlATV mix volumes: L->L, L->R, R->R, R->L */

s32 CdMix(u8* vol);

void func_8001B2E0(s32 stereo) {
    D_800D1599 = stereo;
    if ((u8)stereo) {
        D_800E8184[0] = D_80070C50;
        D_800E8184[1] = 0;
        D_800E8184[2] = D_80070C50;
        D_800E8184[3] = 0;
    } else {
        D_800E8184[0] = D_80070C50 >> 1;
        D_800E8184[1] = D_80070C50 >> 1;
        D_800E8184[2] = D_80070C50 >> 1;
        D_800E8184[3] = D_80070C50 >> 1;
    }
    CdMix(D_800E8184);
}
