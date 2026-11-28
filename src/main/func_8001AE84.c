#include "types.h"

extern void SsSetSerialAttr(s32, s32, s32);
extern s32 CdMix(u8* vol);
extern u32 D_80070C50;
extern u8 D_800D1599;
extern u8 D_800E8184[4]; /* CdlATV mix volumes: L->L, L->R, R->R, R->L */

void func_8001AE84(void) {
    s32 i;

    SsSetSerialAttr(0, 0, 1);
    if (D_800D1599 != 0) {
        i = 0;
        do {
            D_800E8184[0] = i;
            D_800E8184[1] = 0;
            D_800E8184[2] = i;
            D_800E8184[3] = 0;
            CdMix(D_800E8184);
            i += 2;
        } while (D_80070C50 >= (u32)i);
        return;
    }
    i = 0;
    do {
        s32 v = i / 2;
        D_800E8184[0] = v;
        D_800E8184[1] = v;
        D_800E8184[2] = v;
        D_800E8184[3] = v;
        CdMix(D_800E8184);
        i += 2;
    } while (D_80070C50 >= (u32)i);
}
